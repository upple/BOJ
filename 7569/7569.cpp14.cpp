#include<iostream>
#include<queue>
#include<vector>

using namespace std;
const int NO_DIRECTION=6;

class mnh
{
public:
    int m, n, h;

    mnh(int x, int y, int z)
    {
        h=x; n=y; m=z;
    }
};

int main()
{
    int M, N, H, ripe=0, unripe=0, day=0;
    cin>>M>>N>>H;
    queue<mnh> Queue;
    vector<mnh> direction;
    direction.push_back(mnh(1,0,0)), direction.push_back(mnh(-1,0,0)), direction.push_back(mnh(0,1,0));
    direction.push_back(mnh(0,-1,0)), direction.push_back(mnh(0,0,1)), direction.push_back(mnh(0,0,-1));

    int ***box=new int **[H];
    for(int i=0; i<H; i++)
    {
        box[i]=new int*[N];
        for(int j=0; j<N; j++)
            box[i][j]=new int[M];
    }

    for(int i=0; i<H; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<M; k++)
            {
                cin>>box[i][j][k];
                if(box[i][j][k]==1)
                {
                    ripe++;
                    box[i][j][k]=-1;
                    Queue.push(mnh(i, j, k));
                }

                else if(box[i][j][k]==0)
                    unripe++;
            }

    if(unripe==0)
    {
        cout<<0<<endl;
        return 0;
    }

    while(Queue.empty()==0)
    {
        if(ripe--==0)
            ripe=Queue.size()-1, day++;

        for(int i=0; i<NO_DIRECTION; i++)
        {
            int x, y, z;
            x=Queue.front().h+direction.at(i).h;
            y=Queue.front().n+direction.at(i).n;
            z=Queue.front().m+direction.at(i).m;

            if(x<0 || x>=H || y<0 || y>=N || z<0 || z>=M)
                continue;

            if(box[x][y][z]==0)
            {
                Queue.push(mnh(x, y, z));
                box[x][y][z]=-1;
                unripe--;
            }

        }
        Queue.pop();
    }

    if(unripe>0)
    {
        cout<<-1<<endl;
        return 0;
    }

    cout<<day<<endl;
    return 0;
}
