int bin[31];
int k, now, i;
bool flag;
int weight(int w) {
  int i;
  for (i = 30; i >= 0; --i) {
    if (bin[i] <= w) {
      return i;
    }
  }
}
// 多项式除法
bool divide(int a, int b) {
  int wa, wb;

  wa = weight(a);
  wb = weight(b);
  b = b << (wa - wb);
  while (a != b && wa >= wb) {
    a ^= b;
    while (bin[wa] > a) {
      --wa;
      b >>= 1;
    }
  }
  return (wa >= wb);
}
void init() {
  int i;
  bin[0] = 1;
  for (i = 1; i <= 30; ++i) {
    bin[i] = bin[i - 1] * 2;
  }
}
void print(int p) {
  int i;
  if (k == 1) {
    cout << ‘x’ << endl;
    return;
  }
 for (i = 30; i >= 1; --i) {
    if (bin[i] <= p) {
      p -= bin[i];
      cout << “x^” << i << ‘+’;
    }
  cout << 1 << endl;
}
int main() {
  freopen(“PRIME.IN”, “r”, stdin);
  freopen(“PRIME.OUT”, “w”, stdout);
  init();
  cin >> k;

 while (k != 0) {
    now = bin[k] - 1;
    do {
      now += 2;
      flag = true;
      for (i = 2; i <= bin[(k+1) / 2+1]-1; ++i) {
        if (divide(now, i)) {
          flag = false;
          break;
        }
    } while (!flag);
    print(now);
    cin >> k;
  }
  return 0;
}
