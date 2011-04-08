#include <QtCore/QCoreApplication>
#include "iostream"
#include "fstream"

using namespace std;


int compress()
{
        char buffer;
        int count=-1;
        char old_buffer;
        cout << count << endl;
        ifstream in_file("test.txt");
        ofstream out_file("test.rle");
        while(!in_file.eof())
        {
                old_buffer = buffer;
                in_file >> buffer;
                while(old_buffer == buffer)
                {
                        count++;
                }
                old_buffer = buffer;
                out_file << old_buffer;
/*
                while((buffer==old_buffer)&&!in_file.eof())
                {
                        count++;
                        old_buffer=buffer;
                        in_file >> buffer;
                        cout << buffer << " " << count << endl;
                }
                out_file << buffer;
                if(count>=0) out_file << count;
                count=-1;
                old_buffer=buffer;
*/

        }
        return 0;
}

int dcompress()
{
    return 0;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
