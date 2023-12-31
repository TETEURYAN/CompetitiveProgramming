// ANS contains the intersecting of points
void solve(){
	ll n,i,n1,ans=0,j=0;
	cin >> n;

	n1=n;

	vpi v;
	ordered_set s;
	sort(all(v));

	for(int i = 0; i < n; i++) s.insert(v[i].s);

	for(int i = 0; i < n; i++){
		ll ct = s.order_of_key(v[i].s); //Emulate de position of v.[i] in s
		ans += ct;
		s.erase(v[i].s);//Clear position
	}

}
