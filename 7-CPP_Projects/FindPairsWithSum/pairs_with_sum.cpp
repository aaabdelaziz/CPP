void findPair(int arr[], int n, int x) {
  unordered_map<int, int> umap;
  for (int i = 0; i < n; i++) {
    int temp = x - arr[i];
    if (umap.find(temp) != umap.end()) {
      int count = umap[temp];
      for (int j = 0; j < count; j++)
        cout << arr[i] << " " << temp << "\n";
    }
    umap[arr[i]]++;
  }
}