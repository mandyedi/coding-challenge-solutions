#define toStr(str) #str
#define io(x) cin >> x
#define FUNCTION(fn, op) void fn(int &current, const int &x){ (x op current) ? current = x : false; }
#define INF 0xffffffff
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)