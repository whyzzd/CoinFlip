#include "gameconfig.h"

GameConfig::GameConfig(QObject *parent) : QObject(parent)
{
    //第一关一定可以玩
    //levelLock[0]=true;
    //从文件中读取数据关卡锁的数据：
    //1，首先判断文件是否为空，
    //  如果不为空将文件中的数据同步到levellock中，
    //  如果为空或不存在，那么将level中的数据同步到文件中

    int arr1[4][4]={{1,1,1,1},
                   {1,1,0,1},
                   {1,0,0,0},
                   {1,1,0,1}};
    QVector<QVector<int>> v;
    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr1[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(1,v);
    v.clear();
    //---------上为第一关----------------
    //后面关卡随机生成吧

    int arr2[4][4]={{1,0,1,1},//2 22 44
                   {0,0,0,1},
                   {1,0,1,0},
                   {1,1,0,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr2[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(2,v);
    v.clear();

    int arr3[4][4]={{1,1,1,1},//3 14 23
                   {1,0,1,1},
                   {1,0,0,1},
                   {0,1,1,1}};
    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr3[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(3,v);
    v.clear();

    int arr4[4][4]={{0,0,1,1},//4 11 33 44
                   {0,1,0,1},
                   {1,0,0,1},
                   {1,1,1,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr4[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(4,v);
    v.clear();

    int arr5[4][4]={{1,1,1,0},//5 24 32 41
                   {1,0,0,1},
                   {1,0,0,1},
                   {0,0,0,1}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr5[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(5,v);
    v.clear();

    int arr6[4][4]={{0,0,1,0},//6 11 23 42
                   {0,0,0,0},
                   {0,0,0,0},
                   {1,0,1,1}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr6[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(6,v);
    v.clear();

    int arr7[4][4]={{0,1,1,1},//7 12 13 43
                   {1,0,1,0},
                   {1,0,0,0},
                   {0,1,1,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr7[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(7,v);
    v.clear();

    int arr8[4][4]={{1,1,0,1},//8 14 32 43
                   {1,0,0,1},
                   {0,1,1,0},
                   {0,0,1,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr8[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(8,v);
    v.clear();

    int arr9[4][4]={{1,0,0,1},//9 22 32 44
                   {0,1,1,0},
                   {1,0,0,0},
                   {1,1,0,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr9[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(9,v);
    v.clear();

    int arr10[4][4]={{1,1,0,1},//10 13 32 44
                   {0,0,0,0},
                   {0,0,0,0},
                   {0,1,0,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr10[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(10,v);
    v.clear();

    int arr11[4][4]={{0,1,1,1},//11 11 13 22 43
                   {0,0,0,0},
                   {0,1,0,0},
                   {0,1,1,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr11[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(11,v);
    v.clear();

    int arr12[4][4]={{0,1,1,0},//12 14 21 31 33
                   {1,0,1,1},
                   {0,0,0,0},
                   {0,0,0,1}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr12[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(12,v);
    v.clear();

    int arr13[4][4]={{0,1,1,1},//13 11 22 33 44
                   {1,0,1,1},
                   {1,1,0,1},
                   {1,1,1,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr13[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(13,v);
    v.clear();

    int arr14[4][4]={{0,1,0,0},//14 12 23 34 41
                   {0,1,1,0},
                   {1,0,1,1},
                   {1,1,0,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr14[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(14,v);
    v.clear();

    int arr15[4][4]={{1,0,0,1},//15 12 21 33 44
                   {0,1,0,1},
                   {0,0,0,1},
                   {1,1,1,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr15[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(15,v);
    v.clear();

    int arr16[4][4]={{0,0,1,1},//16 14 21 32 43
                   {1,1,0,1},
                   {0,1,1,0},
                   {0,0,1,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr16[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(16,v);
    v.clear();

    int arr17[4][4]={{0,1,0,0},//17 12 24 33 41
                   {0,0,0,0},
                   {0,1,0,0},
                   {0,0,1,1}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr17[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(17,v);
    v.clear();

    int arr18[4][4]={{1,1,0,1},//18 13 23 32 44
                   {0,1,0,0},
                   {1,1,1,0},
                   {0,0,0,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr18[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(18,v);
    v.clear();

    int arr19[4][4]={{0,1,0,1},//19 11 22 33 44 32
                   {1,1,0,0},
                   {1,1,1,1},
                   {1,1,1,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr19[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(19,v);
    v.clear();

    int arr20[4][4]={{0,0,0,0},//20 12 23 34 41 22
                   {1,0,0,0},
                   {1,1,1,1},
                   {1,1,0,0}};

    for(int i=0;i<4;i++)
    {
        QVector<int>v0;
        for(int j=0;j<4;j++)
        {
            v0.push_back(arr20[i][j]);
        }
        v.push_back(v0);
    }
    this->mData.insert(20,v);
    v.clear();





}
