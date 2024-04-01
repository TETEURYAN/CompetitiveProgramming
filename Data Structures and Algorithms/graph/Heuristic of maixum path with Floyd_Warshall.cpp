vector<vector<int>> floyd(vector<vector<int>> &grafo) {
  for (int i = 0; i < grafo.size(); i++) {
    for (int j = 0; j < grafo[i].size(); j++) {
        if(i == j) grafo[i][j] = 0;
        grafo[i][j] = -grafo[i][j];
    }
  }

  for (int k = 0; k < grafo.size(); k++) {
    for (int i = 0; i < grafo.size(); i++) {
      for (int j = 0; j < grafo.size(); j++) {
        grafo[i][j] = max(grafo[i][j], grafo[i][k] + grafo[k][j]);
      }
    }
  }

  for (int i = 0; i < grafo.size(); i++) {
    for (int j = 0; j < grafo[i].size(); j++) {
      grafo[i][j] = -grafo[i][j];
    }
  }

  return grafo;
}
