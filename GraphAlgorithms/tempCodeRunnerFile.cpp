vis.resize(cnt + 1);
        ll mx = 0;
        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < cnt; i++)
        {
            if (!vis[i])
            {
                mx = max(mx, dfs3(i, dadj));
            }
        }
        return mx;