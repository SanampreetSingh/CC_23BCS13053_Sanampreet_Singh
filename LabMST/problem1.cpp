 #include<bits/stdc++.h>
 using namespace std;
 
  int main(){
       ios::sync_with_stdio(false);
       cin.tie(nullptr);

       int n;
       cin>>n;
       long long sum=0;
       vector<vector<int>>v(n,vector<int>(2));
       for(int i =0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
        sum+=v[i][1];
       }
       sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
         return a[1]>b[1];
       });

       long long left=v[0][1],right=sum,ans=sum;
       while(left<=right){
       long long mid=(left+right)/2;
       bool check=true;
       long long temp=mid; 
       for(int i = 0;i<n;i++){
         if(temp<v[i][1]) check=false;
         temp-=v[i][0];
        }
        if(!check ||temp<0)left=mid+1;
        else{
            right=mid-1;
            ans=mid;
        }
       }
       cout<<ans<<endl;

       return 0;
       }