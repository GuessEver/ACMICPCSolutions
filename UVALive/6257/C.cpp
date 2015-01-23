#include <cstdio>
#include <cstring>

int ele['z'+10]['z'+10];

void fuck()
{
	ele['h'][0] = 1;
	ele['l']['i'] = 1;
	ele['n']['a'] = 1;
	ele['k'][0] = 1;
	ele['r']['b'] = 1;
	ele['c']['s'] = 1;
	ele['f']['r'] = 1;
	
	ele['b']['e'] = 1;
	ele['m']['g'] = 1;
	ele['c']['a'] = 1;
	ele['s']['r'] = 1;
	ele['b']['a'] = 1;
	ele['r']['a'] = 1;
	
	ele['b'][0] = 1;
	ele['a']['l'] = 1;
	ele['g']['a'] = 1;
	ele['i']['n'] = 1;
	ele['t']['l'] = 1;
	
	ele['c'][0] = 1;
	ele['s']['i'] = 1;
	ele['g']['e'] = 1;
	ele['s']['n'] = 1;
	ele['p']['b'] = 1;
	ele['f']['l'] = 1;
	
	ele['n'][0] = 1;
	ele['p'][0] = 1;
	ele['a']['s'] = 1;
	ele['s']['b'] = 1;
	ele['b']['i'] = 1;
	
	ele['o'][0] = 1;
	ele['s'][0] = 1;
	ele['s']['e'] = 1;
	ele['t']['e'] = 1;
	ele['p']['o'] = 1;
	ele['l']['v'] = 1;
	
	ele['f'][0] = 1;
	ele['c']['l'] = 1;
	ele['b']['r'] = 1;
	ele['i'][0] = 1;
	ele['a']['t'] = 1;
	
	ele['h']['e'] = 1;
	ele['n']['e'] = 1;
	ele['a']['r'] = 1;
	ele['k']['r'] = 1;
	ele['x']['e'] = 1;
	ele['r']['n'] = 1;
	
	ele['s']['c'] = 1;
	ele['t']['i'] = 1;
	ele['v'][0] = 1;
	ele['c']['r'] = 1;
	ele['m']['n'] = 1;
	ele['f']['e'] = 1;
	ele['c']['o'] = 1;
	ele['n']['i'] = 1;
	ele['c']['u'] = 1;
	ele['z']['n'] = 1;
	
	ele['y'][0] = 1;
	ele['z']['r'] = 1;
	ele['n']['b'] = 1;
	ele['m']['o'] = 1;
	ele['t']['c'] = 1;
	ele['r']['u'] = 1;
	ele['r']['h'] = 1;
	ele['p']['d'] = 1;
	ele['a']['g'] = 1;
	ele['c']['d'] = 1;
	
	ele['l']['a'] = 1;
	ele['c']['e'] = 1;
	ele['p']['r'] = 1;
	ele['n']['d'] = 1;
	ele['p']['m'] = 1;
	ele['s']['m'] = 1;
	ele['e']['u'] = 1;
	ele['g']['d'] = 1;
	ele['t']['b'] = 1;
	ele['d']['y'] = 1;
	ele['h']['o'] = 1;
	ele['e']['r'] = 1;
	ele['t']['m'] = 1;
	ele['y']['b'] = 1;
	ele['l']['u'] = 1;
	
	ele['h']['f'] = 1;
	ele['t']['a'] = 1;
	ele['w'][0] = 1;
	ele['r']['e'] = 1;
	ele['o']['s'] = 1;
	ele['i']['r'] = 1;
	ele['p']['t'] = 1;
	ele['a']['u'] = 1;
	ele['h']['g'] = 1;
	
	ele['a']['c'] = 1;
	ele['t']['h'] = 1;
	ele['p']['a'] = 1;
	ele['u'][0] = 1;
	ele['n']['p'] = 1;
	ele['p']['u'] = 1;
	ele['a']['m'] = 1;
	ele['c']['m'] = 1;
	ele['b']['k'] = 1;
	ele['c']['f'] = 1;
	ele['e']['s'] = 1;
	ele['f']['m'] = 1;
	ele['m']['d'] = 1;
	ele['n']['o'] = 1;
	ele['l']['r'] = 1;
	
	ele['r']['f'] = 1;
	ele['d']['b'] = 1;
	ele['s']['g'] = 1;
	ele['b']['h'] = 1;
	ele['h']['s'] = 1;
	ele['m']['t'] = 1;
	ele['d']['s'] = 1;
	ele['r']['g'] = 1;
	ele['c']['n'] = 1;
}

char s[50010];
int n;
bool f[50010];

int main()
{
	fuck();
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		n = strlen(s);
		memset(f, 0, sizeof(f));
		f[0] = ele[s[0]][0];
		for(int i = 1; i < n; i++)
		{
			if(ele[s[i]][0] && f[i-1]) f[i] = 1;
			if(ele[s[i-1]][s[i]] && (i == 1 || (i > 1 && f[i-2]))) f[i] = 1;
		}
		if(f[n-1]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
