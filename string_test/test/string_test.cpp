#include <iostream>
#include <string>
#include <cstring>
#include <vector>

//1.结尾出现一个或多个分割字符 2.分割字符连续出现 3.分割字符由多个重复字符组成
std::vector<std::string> SplitString(const std::string &sStr, const std::string &sMark)
{
     std::vector<std::string> svResult;
     std::string::size_type stPos = std::string::npos;
     std::string sValTmp(sStr);
     sValTmp += sMark;
     for (size_t i = 0; i < sValTmp.size(); i++) {
          stPos = sValTmp.find(sMark, i);    //stPos是否会出现越界
          std::string sTmp = sValTmp.substr(i, stPos - i);
          svResult.push_back(sTmp);
          i = stPos + sMark.size() - 1;
     }
     return svResult;
}

int main(int argc, char **argv)
{

     std::string str = "1232125,hbjnb,njhuy";
     std::vector<std::string> result=SplitString(str,",,");
     for(std::vector<std::string>::const_iterator iter = result.begin(); iter != result.end(); ++iter) {
          std::cout << *iter << std::endl;
     }
     std::cout << "String Split Result Number: " << result.size() << std::endl;
     std::cout << "--- test end ---" << std::endl;


     int a,b;
     std::string str1 = "1243asd";
     try{
          a = stoi(str1);
          std::cout << a << std::endl;
     } catch(...) {
          std::cout << "transport to int failed" << std::endl;
     }
     b = atoi(str1.c_str());
     std::cout << a << std::endl;
     std::cout << "--- test end ---" << std::endl;


     return 0;
}