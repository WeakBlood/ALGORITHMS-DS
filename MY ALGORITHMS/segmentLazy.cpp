#include <iostream>
#include <vector>

using namespace std;

#define ll long long int 

struct Segmento{
    int N;
    vector<ll> segmento,lazy;

    Segmento(int N,const vector<int> &base)
    {
        segmento.resize(N*4);
        lazy.resize(N*4,0);
        buildTree(1,0,N-1,base);
    }

    void buildTree(int index, int left, int right, const vector<int> &base)
    {
        if(left == right)
        {
            segmento[index] = base[left];
        }
        else
        {
            int half = (left + right) / 2;
            buildTree(index * 2, left, half, base);
            buildTree(index*2+1,half+1,right,base);
            segmento[index] = segmento[index * 2] + segmento[index * 2 + 1];
        }
        
    }

    void updateRange(int index, int start, int end, int left, int right, int value)
    {
        //se ho un reminder non ancora eseguito
        if(lazy[index] != 0)
        {
            //praticamente dientico a riga 56 ma con value al posto di lazy index
            segmento[index] = segmento[index] + (end - start + 1) * lazy[index];
            if(start != end)
            {
                lazy[index * 2] = lazy[index*2] + lazy[index];
                lazy[index * 2 + 1] = lazy[index * 2 + 1] + lazy[index];
            }
            lazy[index] = 0;
        }
     //we are going somewhere else :)
        if(start > right || end < left)
        {
            return;
        }

        //overlappppppping

        if(start >= left && end <= right)
        {
            segmento[index] = segmento[index] + (end - start + 1) * value;
            if(start != end)
            {
                lazy[index*2] = lazy[index*2] + value;
                lazy[index*2+1] = lazy[index*2+1] + value;
            }
            return;
        }

        //a bit of overlap

        int half = (start + end) / 2;
        //da notare come vengano cambiati soltano start ed end 
        updateRange(index*2,start,half,left,right,value);
        updateRange(index*2+1,half+1,end,left,right,value);
        segmento[index] = segmento[index * 2] + segmento[index * 2 + 1];
    }

    ll sumSegmenti(int index, int start, int end, int left, int right)
    {
        if(start > end || start > right || left > end)
        {
            return 0;
            //fuori range bro
        }

        if(lazy[index] != 0)
        {
            segmento[index] = segmento[index] + (end - start + 1) * lazy[index];
            if(start != end)
            {
                lazy[index*2] = lazy[index*2] + lazy[index];
                lazy[index * 2 +1] = lazy[index*2+1] + lazy[index];
            }
            lazy[index] = 0;
        }

        //sei nel range giusto
        if(start >= left && end <= right)
        {
            return segmento[index];
        }

        //sei in parte nel range
        int half = (start + end) / 2;

        return sumSegmenti(index*2,start,half,left,right) + sumSegmenti(index*2+1,half+1,end,left,right);
    }
};
int main()
{

    int N,Q,type,l,r,x;
    cin >> N >> Q;

    vector<int> vet(N);

    for(int i = 0; i < N; i++)
    {
        cin >> vet[i];
    }

    Segmento segTreeLazy(N,vet);

    for(int i = 0; i < Q; i++)
    {
        cin >> type;

        if(type == 1)
        {
            cin >> l >> r >> x;
            segTreeLazy.updateRange(1,0,N-1,l-1,r-1,x);
        }
        else
        {
            cin >> x;
            cout << segTreeLazy.sumSegmenti(1,0,N-1,x-1,x-1) << endl;
        }
    }
    return 0;
}