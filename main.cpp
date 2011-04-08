#include "iostream"
#include "fstream"

using namespace std;

int compress_rle()
{
        char buffer;
        char old_buffer;
        int count;
        ifstream in_file("test.txt");
        ofstream out_file("test.tsar");
        in_file >> buffer;
        while(!in_file.eof())
        {
            count=-1;
            while((old_buffer == buffer)&&!in_file.eof())
            {
                count++;
                in_file >> buffer;
            }
            if(count!=-1)
            {
                cout << old_buffer << (char)count;
                out_file << old_buffer << (char)count;
                continue;
            } else {
                cout << buffer;
                out_file << buffer;
            }
            old_buffer = buffer;
            in_file >> buffer;
        }
        return 0;
}

int dcompress_rle()
{
    char buffer;
    char old_buffer;
    int count;
    ifstream in_file("test.tsar");
    in_file >> buffer;
    while(!in_file.eof())
    {
        cout << buffer;
        if(old_buffer==buffer)
        {
            in_file >> buffer;
            count = (int)buffer;
            for(int i=0;i<count;i++)
                cout << old_buffer;
        }
        old_buffer=buffer;
        in_file >> buffer;
    }
    return 0;
}

int compress_haffman()
{
    return 0;
}

int dcompress_haffman()
{
    return 0;
}

int main(int argc, char *argv[])
{

    compress_rle();
    cout << endl;
    dcompress_rle();
    return 0;
}
