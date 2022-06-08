#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct WEB
{
    int number;
    string website;
    string title;
    string text;
};

int main()
{
    WEB *web = new WEB;
    ifstream openfile;
    openfile.open("news.csv",ios::in);//文件读取流
    ofstream writefile;
    writefile.open("pages.txt",ios::out|ios::trunc);//文件写入流
    string buffer;
    web->number = 1;
    while(getline(openfile,buffer))
    {
        int pos = buffer.find("http://");
        if(pos != -1)
        {
            int end = buffer.find(".html");
            web->title = buffer.substr(0,end+5);//获取想要的网址
            // cout<<web->number<<"."<<web->title<<endl;
            writefile<<web->number<<"."<<web->title<<endl;
            web->number++;
        }
    }
    writefile.close();
    return 0;
}