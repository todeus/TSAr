#include "iostream"
#include "fstream"

using namespace std;

int compress_rle()
{
        char buffer;
        char old_buffer;
        int count;
        fstream in_file("test.txt");
        ofstream out_file("test_rle.tsar");
        in_file.get(buffer);
        while(!in_file.eof())
        {
            count=-1;
            while((old_buffer == buffer)&&!in_file.eof())
            {
                count++;
                in_file.get(buffer);
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
            in_file.get(buffer);
        }
        return 0;
}

int dcompress_rle()
{
    char buffer;
    char old_buffer;
    int count;
    fstream in_file("test_rle.tsar");
    in_file.get(buffer);
    while(!in_file.eof())
    {
        cout << buffer;
        if(old_buffer==buffer)
        {
            in_file.get(buffer);
            count = (int)buffer;
            for(int i=0;i<count;i++)
                cout << old_buffer;
        }
        old_buffer=buffer;
        in_file.get(buffer);
    }
    return 0;
}

class nod
{
public:
    int mas;
    char name;
    nod *left;
    nod *right;
    int print(int n);
};

int nod::print(int n)
{
    if(left)
    {
        cout << "0";
        left->print(n+1);
        cout << "-" << left->mas << " ";
    }
    if(right)
    {
        cout << "1";
        right->print(n+1);
        cout << "-" << right->mas << " ";
    }

    return 0;
}



int compress_haffman()
{
    int elem[255];
    for(int i=0;i<255;i++)
        elem[i]=0;

    char buffer;
    fstream in_file("test.txt");

    //-----------Считаем число вхождений каждого символа-----------
    in_file.get(buffer);
    while(!in_file.eof())
    {
        elem[buffer]++;
        in_file.get(buffer);
    }
    //---------Закончили считать-------------


    //---------Забиваем структуры--------
    nod * a[255];
    for(int i=0;i<255;i++)
    {
        a[i] = new nod;
        a[i]->mas = elem[i];
        //a[i]->name = (char)i;
        a[i]->left = NULL;
        a[i]->right = NULL;
    }
    //---------Закончили забивать структуры----------

    //--------Сортировка-----------
    bool t = true;
    nod * buf;
    while(t)
    {
        t = false;
        for(int i=0;i<254;i++)
        {
            if(a[i]->mas < a[i+1]->mas)
            {
                buf = new nod;
                buf->mas = a[i]->mas;
                //buf->name = a[i]->name;
                buf->left = a[i]->left;
                buf->right = a[i]->right;

                a[i] = a[i+1];
                a[i+1] = buf;

                t = true;
            }
        }
    }
    //--------Конец сортировки-------


    //-------Считаем количество используемых символов-------
    int b;
    for(int i=0;i<255;i++)
    {
        if(a[i]->mas == 0) break;
        b = i;
    }
    //-------Закончили считать-----------


        //Рисуем
    for(int i=0;i<=b;i++)
    {
        cout << a[i]->mas << " ";
    }
        //Закончили рисовать
    cout << endl;


    //-------------Строим дерево--------------
    nod * buffr;

    while(b!=0){
        buffr = new nod;
        buffr = a[b-1];
        a[b-1] = new nod;
        a[b-1]->left = a[b];
        a[b-1]->right = buffr;
        a[b-1]->mas = a[b]->mas + buffr->mas;
        b--;

        t = true;
        while(t)
        {
            t = false;
            for(int i=0;i<b;i++)
            {
                if(a[i]->mas < a[i+1]->mas)
                {
                    buf = new nod;
                    buf->mas = a[i]->mas;
                    //buf->name = a[i]->name;
                    buf->left = a[i]->left;
                    buf->right = a[i]->right;

                    a[i] = a[i+1];
                    a[i+1] = buf;

                    t = true;
                }
            }
        }

            //Рисуем
        for(int i=0;i<=b;i++)
        {
            cout << a[i]->mas << " ";
        }
        cout << endl;
            //Закончили рисовать
    }
    //-------------Построили дерево-------------

    //-------Обходим дерева---------------------

    a[0]->print(0);

    //-------Заканчиваем обход дерева-----------

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
    cout << endl;
    compress_haffman();
    cout << endl;
    return 0;
}
