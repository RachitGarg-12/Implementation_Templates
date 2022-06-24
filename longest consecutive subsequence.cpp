ll n,k;cin>>n>>k;

           ll a[n];map<ll,ll> m;set<ll> s;
           fo(i,n){cin>>a[i];m[a[i]]++;s.insert(a[i]);}
           vector<ll> c;
           for(auto i:s){if(m[i]>=k){c.pb(i);}}
            ll v=c.size();
            if(v==0){cout<<-1<<nl;continue;}
            if(v==1){cout<<c[0]<<" "<<c[0]<<nl;continue;}
              
            ll streak=1;ll mxstreak=1;ll l=c[0];ll ans=c[0];
            f1(i,v-1){
                if((c[i]-c[i-1])==1){
                    streak++;
                    if(i==v-1){if(streak>mxstreak){ans=l;mxstreak=streak;}}
               }
               else{
                    if(streak>mxstreak){ans=l;mxstreak=streak;}
                    streak=1;l=c[i];
                    }
        
            }
            cout<<ans<<" "<<ans+mxstreak-1<<nl;