#include <bits/stdc++.h>                                                                                                                                                                    
using namespace std;                                                                                                                                                                        
                                       
struct TwoSAT {                                                                                                                                                                             
  int n = 0;                           
  vector<vector<int>> g;                                                                                                                                                                  
  vector<int> dfn, low, comp, st;                                                                                                                                                         
  vector<char> in_st;                                                                                                                                                                     
  int timer = 0, comp_cnt = 0;                                                                                                                                                            
                                                                                                                                                                                          
  explicit TwoSAT(int vars = 0) { init(vars); }                                                                                                                                           
                                                                                                                                                                                          
  void init(int vars) {                                                                                                                                                                   
      n = vars;                        
      if ((int)g.size() < 2 * n) g.resize(2 * n);                                                                                                                                         
      for (auto &v : g) v.clear();                                                                                                                                                        
  }                                                                                                                                                                                       
                                                                                                                                                                                          
  int add_var() {                                                                                                                                                                         
      int id = n++;                                                                                                                                                                       
      if ((int)g.size() < 2 * n) g.resize(2 * n);                                                                                                                                         
      g[2 * id].clear();                                                                                                                                                                  
      g[2 * id + 1].clear();                                                                                                                                                              
      return id;                                                                                                                                                                          
  }                                                                                                                                                                                       
                                                                                                                                                                                          
  static int lit(int v, bool val) {                                                                                                                                                       
      return (v << 1) | (val ? 1 : 0);                                                                                                                                                    
  }                                                                                                                                                                                       
                                       
  void add_clause(int a, bool va, int b, bool vb) {                                                                                                                                       
      int A = lit(a, va);              
      int B = lit(b, vb);                                                                                                                                                                 
      g[A ^ 1].push_back(B);                                                                                                                                                              
      g[B ^ 1].push_back(A);                                                                                                                                                              
  }                                                                                                                                                                                       
                                                                                                                                                                                          
  void add_implication(int a, bool va, int b, bool vb) {                                                                                                                                  
      add_clause(a, !va, b, vb);                                                                                                                                                          
  }                                                                                                                                                                                       
                                                                                                                                                                                          
  void tarjan(int u) {                                                                                                                                                                    
      dfn[u] = low[u] = ++timer;                                                                                                                                                          
      st.push_back(u);                                                                                                                                                                    
      in_st[u] = 1;                                                                                                                                                                       
                                                                                                                                                                                          
      for (int v : g[u]) {                                                                                                                                                                
          if (!dfn[v]) {                                                                                                                                                                  
              tarjan(v);                                                                                                                                                                  
              low[u] = min(low[u], low[v]);
          } else if (in_st[v]) {                                                                                                                                                          
              low[u] = min(low[u], dfn[v]);                                                                                                                                               
          }                                                                                                                                                                               
      }                                                                                                                                                                                   
                                                                                                                                                                                          
      if (low[u] == dfn[u]) {                                                                                                                                                             
          ++comp_cnt;                                                                                                                                                                     
          while (true) {                                                                                                                                                                  
              int v = st.back();                                                                                                                                                          
              st.pop_back();                                                                                                                                                              
              in_st[v] = 0;                                                                                                                                                               
              comp[v] = comp_cnt;                                                                                                                                                         
              if (v == u) break;                                                                                                                                                          
          }                                                                                                                                                                               
      }                                                                                                                                                                                   
  }                                                                                                                                                                                       
                                                                                                                                                                                          
  bool satisfiable() {                                                                                                                                                                    
      int m = 2 * n;                                                                                                                                                                      
      dfn.assign(m, 0);                                                                                                                                                                   
      low.assign(m, 0);                                                                                                                                                                   
      comp.assign(m, 0);                                                                                                                                                                  
      in_st.assign(m, 0);                                                                                                                                                                 
      st.clear();                                                                                                                                                                         
      timer = comp_cnt = 0;                                                                                                                                                               
                                                                                                                                                                                          
      for (int i = 0; i < m; ++i) {                                                                                                                                                       
          if (!dfn[i]) tarjan(i);                                                                                                                                                         
      }                                                                                                                                                                                   
                                                                                                                                                                                          
      for (int i = 0; i < n; ++i) {                                                                                                                                                       
          if (comp[2 * i] == comp[2 * i + 1]) return false;                                                                                                                               
      }                                                                                                                                                                                   
      return true;                                                                                                                                                                        
  }                                                                                                                                                                                       
};                                                                                                                                                                                          
                                                                                                                                                                                          
struct Solver {                                                                                                                                                                             
  int n, e, T;                         
  vector<vector<pair<int,int>>> active;                                                                                                                                                   
  vector<int> seg;                                                                                                                                                                        
  TwoSAT ts;                                                                                                                                                                              
                                                                                                                                                                                          
  void build_seg(int node, int l, int r) {                                                                                                                                                
      if (l == r) {                                                                                                                                                                       
          seg[node] = l;                                                                                                                                                                  
          return;                                                                                                                                                                         
      }                                                                                                                                                                                   
      seg[node] = ts.add_var();                                                                                                                                                           
      int mid = (l + r) >> 1;                                                                                                                                                             
      build_seg(node << 1, l, mid);                                                                                                                                                       
      build_seg(node << 1 | 1, mid + 1, r);                                                                                                                                               
                                                                                                                                                                                          
      ts.add_implication(seg[node << 1], true, seg[node], true);                                                                                                                          
      ts.add_implication(seg[node << 1 | 1], true, seg[node], true);                                                                                                                      
  }                                                                                                                                                                                       
                                       
  void forbid_range_if_selected(int node, int l, int r, int ql, int qr, int u) {                                                                                                          
      if (qr < l || r < ql) return;    
      if (ql <= l && r <= qr) {                                                                                                                                                           
          ts.add_implication(u, true, seg[node], false);                                                                                                                                  
          return;                                                                                                                                                                         
      }                                                                                                                                                                                   
      int mid = (l + r) >> 1;                                                                                                                                                             
      forbid_range_if_selected(node << 1, l, mid, ql, qr, u);                                                                                                                             
      forbid_range_if_selected(node << 1 | 1, mid + 1, r, ql, qr, u);                                                                                                                     
  }                                                                                                                                                                                       
                                                                                                                                                                                          
  bool feasible(int D, const vector<pair<int,int>> &edges_at_t) {                                                                                                                         
      ts.init(n);                      
                                                                                                                                                                                          
      for (auto [u, v] : edges_at_t) {                                                                                                                                                    
          ts.add_clause(u, true, v, true);                                                                                                      
      }                                                                                                                                                                                   
                                                                                                                                                                                          
      if (D == n) {                                                                                                                                                                       
          int prev = -1;                                                                                                                                                                  
          for (int i = 0; i < n; ++i) {                                                                                                                                                   
              int p = ts.add_var();                                                                                                                                                       
              ts.add_implication(i, true, p, true);                                                                                                                                       
              if (prev != -1) {                                                                                                                                                           
                  ts.add_implication(prev, true, p, true);                                                                                                                                
                  ts.add_implication(i, true, prev, false);                                                                                                                               
              }                                                                                                                                                                           
              prev = p;                                                                                                                                                                   
          }                                                                                                                                                                               
      } else if (D > 1) {                                                                                                                                                                 
          seg.assign(4 * n + 5, -1);                                                                                                                                                      
          build_seg(1, 0, n - 1);                                                                                                                                                         
                                                                                                                                                                                          
          for (int i = 0; i < n; ++i) {                                                                                                                                                   
              int L = i + 1;                                                                                                                                                              
              int R = i + D - 1;                                                                                                                                                          
                                                                                                                                                                                          
              if (L < n) {                                                                                                                                                                
                  forbid_range_if_selected(1, 0, n - 1, L, min(R, n - 1), i);                                                                                                             
              }                                                                                                                                                                           
              if (R >= n) {                                                                                                                                                               
                  forbid_range_if_selected(1, 0, n - 1, 0, R % n, i);                                                                                                                     
              }                                                                                                                                                                           
          }                                                                                                                                                                               
      }                                                                                                                                                                                   
                                                                                                                                                                                          
      return ts.satisfiable();                                                                                                                                                            
  }                                                                                                                                                                                       
                                                                                                                                                                                          
  void run() {                                                                                                                                                                            
      ios::sync_with_stdio(false);
      cin.tie(nullptr);                                                                                                                                                                   
                                                                                                                                                                                          
      cin >> n >> e >> T;                                                                                                                                                                 
      active.assign(T + 1, {});                                                                                                                                                           
                                                                                                                                                                                          
      for (int i = 0; i < e; ++i) {                                                                                                                                                       
          int u, v, l, r;                                                                                                                                                                 
          cin >> u >> v >> l >> r;                                                                                                                                                        
          --u; --v;                                                                                                                                                                       
          for (int t = l; t <= r; ++t) {                                                                                                                                                  
              active[t].push_back({u, v});                                                                                                                                                
          }                                                                                                                                                                               
      }                                                                                                                                                                                   
                                                                                                                                                                                          
      vector<int> candidates;                                                                                                                                                             
      for (int d = 1; d <= n / 2; ++d) candidates.push_back(d);                                                                                                                           
      candidates.push_back(n);                                                                                                                                                            
                                                                                                                                                                                          
      ts.init(n);                                                                                                                                                                         
                                                                                                                                                                                          
      for (int t = 1; t <= T; ++t) {                                                                                                                                                      
          int lo = 0, hi = (int)candidates.size() - 1;
          int ans = 1;                                                                                                                                                                    
                                                                                                                                                                                          
          while (lo <= hi) {                                                                                                                                                              
              int mid = (lo + hi) >> 1;                                                                                                                                                   
              int D = candidates[mid];                                                                                                                                                    
                                                                                                                                                                                          
              if (feasible(D, active[t])) {                                                                                                                                               
                  ans = D;                                                                                                                                                                
                  lo = mid + 1;                                                                                                                                                           
              } else {                                                                                                                                                                    
                  hi = mid - 1;                                                                                                                                                           
              }                                                                                                                                                                           
          }                                                                                                                                                                               
                                                                                                                                                                                          
          cout << ans << '\n';                                                                                                                                                            
      }
  }                                                                                                                                                                                       
};                                       

int main() {                                                                                                                                                                                
  Solver solver;
  solver.run();                                                                                                                                                                           
  return 0;                            
}         