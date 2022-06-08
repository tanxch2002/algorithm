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
    openfile.open("news.csv",ios::in);
    ofstream writefile;
    writefile.open("pages.txt",ios::out|ios::trunc);
    string buffer;
    web->number = 1;
    while(getline(openfile,buffer))
    {
        int pos = buffer.find("http://");
        if(pos != -1)
        {
            int end = buffer.find(".html");
            web->title = buffer.substr(0,end+5);
            // cout<<web->number<<"."<<web->title<<endl;
            writefile<<web->number<<"."<<web->title<<endl;
            web->number++;
        }
    }
    writefile.close();
    return 0;
}