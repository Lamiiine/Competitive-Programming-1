/* inside or on the border of R => selects R
 * otherwise, selects the closest visible icons
 */
#include<stdio.h>
#include<string.h>
#include<string>
#include<complex>
#include<vector>
#define X real()
#define Y imag()
#define dist(a, b) (hypot((a).X - (b).X, (a).Y - (b).Y))
using namespace std;
typedef complex<int> point;
typedef pair<point, point> region;
typedef pair<point, int> icon;
vector<icon> icons;
vector<region> regions;
char str[15];
inline bool inside_region(const point & click, const region & r)
{
	return click.X >= r.first.X && click.X <= r.second.X && click.Y >= r.first.Y && click.Y <= r.second.Y;
}
inline void set_invisible(void)
{
	vector<icon> visible_icons;
	for (int i = 0; i < icons.size(); ++i)
	{
		bool flag = true;
		for (int j = 0; j < regions.size() && flag; ++j)
		if (inside_region(icons[i].first, regions[j]))
			flag = false;

		if (flag) visible_icons.push_back(icons[i]);
	}
	icons = visible_icons;
}

int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	int icon_counter = 1;
	bool flag = true;
	for (int x, y, z, w; flag && (scanf("%s", str), strcmp(str, "#"));)
	{
		switch (*str)
		{
		case 'I':
		{
					scanf("%d%d", &x, &y);
					icons.push_back(icon(point(x, y), icon_counter++));
					break;
		}
		case 'R':
		{
					scanf("%d%d%d%d", &x, &y, &z, &w);
					regions.push_back(region(point(x, y), point(z, w)));
					break;
		}
		case 'M':
		{
					set_invisible();
					flag = false;
					break;
		}
		default: break;
		}
	}

	if (strcmp(str, "#"))
	do
	{
		int x, y;
		scanf("%d%d", &x, &y);
		// solve for this click
		point click = point(x, y);
		bool found_region = false;
		for (int i = regions.size() - 1; i >= 0; --i)
		{
			if (inside_region(click, regions[i]))
			{
				found_region = true;
				printf("%c", (char)'A' + i);
				break;
			}
		}
		if (!found_region)
		{
			double ans_dist = 1e9;
			vector<int> ans;
			for (int i = 0; i < icons.size(); ++i)
			{
				double cur_dist = dist(icons[i].first, click);
				if (cur_dist < ans_dist)
				{
					ans_dist = cur_dist;
					ans.clear();
					ans.push_back(icons[i].second);
				}
				else if (cur_dist == ans_dist)
					ans.push_back(icons[i].second);
			}
			for (int i = 0; i < ans.size(); ++i)
				printf("%3d", ans[i]);
		}

		printf("\n");
	} while (scanf("%s", str), strcmp(str, "#"));
	return 0;
}