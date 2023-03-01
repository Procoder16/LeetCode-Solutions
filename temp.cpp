// sum of N numbers

int sum(int n) {
  int result = 0;
  for (int i = 1; i <= n; i++) {
    result += i;
  }
  return result;
}

// Find the maximum element in an array

int max_element(int arr[], int n) {
  int result = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > result) {
      result = arr[i];
    }
  }
  return result;
}

// Finding the intersection of two arrays

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> set1(nums1.begin(), nums1.end());
  unordered_set<int> set2(nums2.begin(), nums2.end());
  vector<int> result;
  for (int num : set1) {
    if (set2.count(num)) {
      result.push_back(num);
    }
  }
  return result;
}

// Bubble sort algorithm

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

// Binary Search Algorithm

int binary_search(int arr[], int n, int target) {
  int left = 0, right = n-1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

// Merge sort algorithm

void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void merge_sort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}


// Quick Sort algorithm

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[high]);
  return i+1;
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi-1);
    quick_sort(arr, pi+1, high);
  }
}

// Floyd Warshall Algorithm

void floyd_warshall(int graph[][V]) {
  int dist[V][V], i, j, k;
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      dist[i][j] = graph[i][j];
    }
  }
  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

