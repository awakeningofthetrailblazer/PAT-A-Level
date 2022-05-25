#include<bits/stdc++.h>

using namespace std;

vector<int> origin_seq,refer_seq,res_seq;

void init();

bool insertSort(vector<int> seq);

bool mergeSort(vector<int> seq);

int main(){
    init();
    
    if(insertSort(origin_seq)) {cout<<"Insertion Sort\n";}
    else if(mergeSort(origin_seq)) {cout<<"Merge Sort\n";}
    
    if(res_seq==refer_seq) return -1;
    
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
    while(sorted<refer_seq.size() && refer_seq[sorted-1]<=refer_seq[sorted]) 
        sorted++;
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

bool mergeSort(vector<int> seq){
    int groupsize=2,h1,h2,tail1,tail2;
    bool res=false;
    int len=seq.size();
    
    while(groupsize<len){
        //for(int x:seq) cout<<x<<endl;
        //cout<<endl<<groupsize<<endl;
        if(seq!=origin_seq && seq==refer_seq) res=true;
        
        for(int i=0;i<ceil(double(len)/double(groupsize));i++){
            
            
            h1=i*groupsize;
            h2=min(h1+groupsize/2,len);
            tail1=h2;
            tail2=min(h2+groupsize/2,len);
            
            vector<int> tempseq;
            while(h1<tail1 || h2<tail2){
                if(h1<tail1 && h2<tail2){
                    if(seq[h1]<seq[h2]) {
                        tempseq.push_back(seq[h1]);
                        h1++;
                    }else{
                        tempseq.push_back(seq[h2]);
                        h2++;
                    }
                }else if(h2<tail2){
                    tempseq.push_back(seq[h2]);
                    h2++;
                }else if(h1<tail1){
                    tempseq.push_back(seq[h1]);
                    h1++;
                }
            }
            
            for(int k=0;k<tempseq.size();k++) {
                seq[i*groupsize+k]=tempseq[k];
                //cout<<i+k<<' '<<k<<' '<<seq[i*groupsize+k]<<endl;
            }
            
        }
        
        if(res){
            res_seq=seq;
            break;
        }
        
        groupsize*=2;
    }
    
    return res;
}
