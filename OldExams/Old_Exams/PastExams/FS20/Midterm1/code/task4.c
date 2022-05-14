for (i=1; i<=ceil((N+1)/2); i++) {
  for (j=i; j<=N-i; j++) {
    if (A[j] > A[j+1]) {
      exchange(A[j], A[j+1]);
    }	
  }
  for (k=N-i; k>i; k--) {
    if (A[k] < A[k-1]) {
      exchange(A[k], A[k-1]);
    }
  }
}
