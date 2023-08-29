#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

class BoolStr
{
public:
    BoolStr()
        : oneBool(true){};
    std::atomic<bool> oneBool;
};

class BoolStrReader
{
public:
    void ReadBool(const size_t& index)
    {
        while (true)
        {
            std::cout << boolVect.at(index)->oneBool.load() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    };
    std::vector<boost::shared_ptr<BoolStr>> boolVect;
};


int main(int argc, char** argv)
{
    boost::asio::io_service ioService;
    boost::thread_group threadpool;
    boost::shared_ptr<boost::asio::io_service::work> work(
        new boost::asio::io_service::work(ioService));
    for (size_t i = 0; i < 500; ++i)
    {
        threadpool.create_thread(
            boost::bind(&boost::asio::io_service::run, &ioService));
    }
    boost::shared_ptr<BoolStrReader> newReader(new BoolStrReader);
    for (size_t i = 0; i < 500; ++i)
    {
        boost::shared_ptr<BoolStr> tmpBool(new BoolStr);
        newReader->boolVect.push_back(tmpBool);
        ioService.post(boost::bind(&BoolStrReader::ReadBool, newReader, i));
    }
}