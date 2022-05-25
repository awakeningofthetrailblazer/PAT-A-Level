#include<bits/stdc++.h>

using namespace std;

vector<int> origin_seq,refer_seq,res_seq;

void init();

bool insertSort(vector<int> seq);

bool heapSort(vector<int> seq);

void heapBuild(vector<int>& seq,int rk,int n);

int main(){
    init();
    
    if(insertSort(origin_seq)) {cout<<"Insertion Sort"<<endl;}
    else if(heapSort(origin_seq)) cout<<"Heap Sort"<<endl;
    
    for(int i=0;i<res_seq.size();i++){
        cout<<res_seq[i];
        if(i==res_seq.size()-1) cout<<endl;
        else cout<<' ';
    }
    
    return 0;
}

void init(){
    int N,x;
    
    cin>>N;
    int tempN=N;
    
    while(tempN--){
        cin>>x;
        origin_seq.push_back(x);
    }
    tempN=N;
    while(tempN--){
        cin>>x;
        refer_seq.push_back(x);
    }
}

bool insertSort(vector<int> seq){
    bool res=false;
    int sorted=1;
    //cout<<refer_seq.size()<<endl;
    while(sorted<refer_seq.size() && refer_seq[sorted-1]<=refer_seq[sorted]) {
        //cout<<refer_seq[sorted]<<endl;
        sorted++;
    }
    int rk=sorted;
    while(sorted<seq.size() && refer_seq[sorted]==seq[sorted]) sorted++;
    if(sorted==seq.size()) res=true;
    
    if(res){
        int k=rk,val=refer_seq[rk];
        seq=refer_seq;
        
        for(;seq[k-1]>=val && k>0;k--) seq[k]=seq[k-1];
        seq[k]=val;
        
        res_seq=seq;
    }
    
    return res;
}

bool heapSort(vector<int> seq){
    bool res=false;
    
    //建堆
    int n=seq.size();
    for(int k=n/2-1;k>=0;k--){
        heapBuild(seq,k,n);
    }
    
    //for(int x:seq) cout<<x<<' ';
    //cout<<endl;
    
    //堆排序
    for(int p=n-1;p>=0;p--){
        if(seq==refer_seq) res=true;
        
        swap(seq[0],seq[p]);
        
        heapBuild(seq,0,p);
        
        if(res){
            res_seq=seq;
            break;
        }
    }
    
    return res;
}

void heapBuild(vector<int>& seq, int rk, int n){
    int te;
    while(true){
        if(2*rk+1<n && 2*rk+2<n){
            te=seq[2*rk+1]>seq[2*rk+2]?2*rk+1:2*rk+2;
            if(seq[rk]<seq[te]){
                swap(seq[rk],seq[te]);
                rk=te;
            }else break;
        }else if(2*rk+1<n || 2*rk+2<n){
            te=2*rk+1<n?2*rk+1:2*rk+2;
            if(seq[rk]<seq[te]){
                swap(seq[rk],seq[te]);
                rk=te;
            }else break;
        }else break;
    }
}
