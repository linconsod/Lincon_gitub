/* 100 C Programming Problems with Solutions (single file)
 *
 * Compile : gcc c_100_problems.c -o c100 -lm
 * Run     : ./c100        -> show list of all problems
 *           ./c100 25     -> run problem number 25
 *           ./c100 all    -> run all problems
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define P(n) static void p##n(void)
#define PI 3.14159265358979

static void printarr(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

/* ===================== BASICS (1-30) ===================== */
P(1)  { printf("Hello, World!\n"); }
P(2)  { int a = 15, b = 27; printf("Sum = %d\n", a + b); }
P(3)  { int a = 5, b = 9, t; t = a; a = b; b = t; printf("a=%d b=%d\n", a, b); }
P(4)  { int a = 5, b = 9; a = a + b; b = a - b; a = a - b; printf("a=%d b=%d\n", a, b); }
P(5)  { int n = 17; printf("%d is %s\n", n, n % 2 ? "odd" : "even"); }
P(6)  { int a = 12, b = 45, c = 30, m = a; if (b > m) m = b; if (c > m) m = c; printf("Largest = %d\n", m); }
P(7)  { int y = 2024; printf("%d is %sa leap year\n", y, ((y % 4 == 0 && y % 100) || y % 400 == 0) ? "" : "not "); }
P(8)  { double p = 5000, r = 5, t = 2; printf("Simple Interest = %.2f\n", p * r * t / 100); }
P(9)  { double r = 7; printf("Area of circle = %.2f\n", PI * r * r); }
P(10) { double c = 37; printf("%.1f C = %.1f F\n", c, c * 9 / 5 + 32); }
P(11) { int n = -8; printf("%d is %s\n", n, n > 0 ? "positive" : n < 0 ? "negative" : "zero"); }
P(12) {
    char c = tolower('e');
    if (!isalpha(c)) printf("Not a letter\n");
    else printf("%c is a %s\n", c, strchr("aeiou", c) ? "vowel" : "consonant");
}
P(13) {
    int m = 76; char g;
    if (m >= 80) g = 'A'; else if (m >= 70) g = 'B'; else if (m >= 60) g = 'C';
    else if (m >= 50) g = 'D'; else g = 'F';
    printf("Marks %d -> Grade %c\n", m, g);
}
P(14) {
    double a = 20, b = 4, r; char op[] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++) {
        switch (op[i]) {
            case '+': r = a + b; break;
            case '-': r = a - b; break;
            case '*': r = a * b; break;
            default:  r = a / b;
        }
        printf("%.0f %c %.0f = %.2f\n", a, op[i], b, r);
    }
}
P(15) { int n = 4821, s = 0; while (n) { s += n % 10; n /= 10; } printf("Sum of digits = %d\n", s); }
P(16) { int n = 12345, r = 0; while (n) { r = r * 10 + n % 10; n /= 10; } printf("Reversed = %d\n", r); }
P(17) { int n = 12321, o = n, r = 0; while (n) { r = r * 10 + n % 10; n /= 10; } printf("%d is %sa palindrome\n", o, r == o ? "" : "not "); }
P(18) { int n = 10; unsigned long long f = 1; for (int i = 2; i <= n; i++) f *= i; printf("%d! = %llu\n", n, f); }
P(19) { int a = 0, b = 1; for (int i = 0; i < 10; i++) { printf("%d ", a); int t = a + b; a = b; b = t; } printf("\n"); }
P(20) { int n = 29, ok = n > 1; for (int i = 2; i * i <= n; i++) if (n % i == 0) { ok = 0; break; } printf("%d is %sprime\n", n, ok ? "" : "not "); }
P(21) {
    for (int n = 2; n <= 50; n++) {
        int ok = 1;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) { ok = 0; break; }
        if (ok) printf("%d ", n);
    }
    printf("\n");
}
P(22) { int n = 153, o = n, s = 0; while (n) { int d = n % 10; s += d * d * d; n /= 10; } printf("%d is %san Armstrong number\n", o, s == o ? "" : "not "); }
P(23) { int a = 48, b = 18; while (b) { int t = a % b; a = b; b = t; } printf("GCD = %d\n", a); }
P(24) { int a = 12, b = 18, x = a, y = b; while (y) { int t = x % y; x = y; y = t; } printf("LCM = %d\n", a / x * b); }
P(25) { int x = 2, n = 10; long r = 1; for (int i = 0; i < n; i++) r *= x; printf("%d^%d = %ld\n", x, n, r); }
P(26) { int n = 987654, c = 0; do { c++; n /= 10; } while (n); printf("Digits = %d\n", c); }
P(27) { int n = 7; for (int i = 1; i <= 10; i++) printf("%d x %d = %d\n", n, i, n * i); }
P(28) { int n = 100; printf("Sum of 1 to %d = %d\n", n, n * (n + 1) / 2); }
P(29) { int n = 28, s = 0; for (int i = 1; i < n; i++) if (n % i == 0) s += i; printf("%d is %sa perfect number\n", n, s == n ? "" : "not "); }
P(30) {
    int n = 145, o = n, s = 0;
    while (n) { int d = n % 10, f = 1; for (int i = 2; i <= d; i++) f *= i; s += f; n /= 10; }
    printf("%d is %sa strong number\n", o, s == o ? "" : "not ");
}

/* ===================== PATTERNS (31-36) ===================== */
P(31) { for (int i = 1; i <= 5; i++) { for (int j = 0; j < i; j++) printf("* "); printf("\n"); } }
P(32) { for (int i = 1; i <= 5; i++) { printf("%*s", 5 - i, ""); for (int j = 0; j < 2 * i - 1; j++) printf("*"); printf("\n"); } }
P(33) { for (int i = 1; i <= 5; i++) { for (int j = 1; j <= i; j++) printf("%d ", j); printf("\n"); } }
P(34) { int k = 1; for (int i = 1; i <= 5; i++) { for (int j = 0; j < i; j++) printf("%d ", k++); printf("\n"); } }
P(35) {
    int n = 4;
    for (int i = 1; i <= n; i++) { printf("%*s", n - i, ""); for (int j = 0; j < 2 * i - 1; j++) printf("*"); printf("\n"); }
    for (int i = n - 1; i >= 1; i--) { printf("%*s", n - i, ""); for (int j = 0; j < 2 * i - 1; j++) printf("*"); printf("\n"); }
}
P(36) {
    for (int i = 0; i < 6; i++) {
        printf("%*s", (5 - i) * 2, "");
        int c = 1;
        for (int j = 0; j <= i; j++) { printf("%4d", c); c = c * (i - j) / (j + 1); }
        printf("\n");
    }
}

/* ===================== ARRAYS & MATRICES (37-60) ===================== */
P(37) { int a[] = {4, 8, 15, 16, 23, 42}, n = 6, s = 0; for (int i = 0; i < n; i++) s += a[i]; printf("Sum = %d, Average = %.2f\n", s, (double)s / n); }
P(38) { int a[] = {34, 7, 89, 21, 56}, n = 5, mx = a[0], mn = a[0]; for (int i = 1; i < n; i++) { if (a[i] > mx) mx = a[i]; if (a[i] < mn) mn = a[i]; } printf("Max = %d, Min = %d\n", mx, mn); }
P(39) { int a[] = {1, 2, 3, 4, 5}, n = 5; for (int i = n - 1; i >= 0; i--) printf("%d ", a[i]); printf("\n"); }
P(40) { int a[] = {9, 4, 7, 2, 6}, n = 5, k = 7, p = -1; for (int i = 0; i < n; i++) if (a[i] == k) { p = i; break; } if (p >= 0) printf("%d found at index %d\n", k, p); else printf("%d not found\n", k); }
P(41) {
    int a[] = {2, 5, 8, 12, 16, 23, 38}, lo = 0, hi = 6, k = 23, p = -1;
    while (lo <= hi) { int m = (lo + hi) / 2; if (a[m] == k) { p = m; break; } if (a[m] < k) lo = m + 1; else hi = m - 1; }
    printf("Index of %d = %d\n", k, p);
}
P(42) { int a[] = {64, 34, 25, 12, 22, 11, 90}, n = 7; for (int i = 0; i < n - 1; i++) for (int j = 0; j < n - i - 1; j++) if (a[j] > a[j + 1]) { int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; } printarr(a, n); }
P(43) { int a[] = {29, 10, 14, 37, 13}, n = 5; for (int i = 0; i < n - 1; i++) { int m = i; for (int j = i + 1; j < n; j++) if (a[j] < a[m]) m = j; int t = a[i]; a[i] = a[m]; a[m] = t; } printarr(a, n); }
P(44) { int a[] = {12, 11, 13, 5, 6}, n = 5; for (int i = 1; i < n; i++) { int k = a[i], j = i - 1; while (j >= 0 && a[j] > k) { a[j + 1] = a[j]; j--; } a[j + 1] = k; } printarr(a, n); }
P(45) {
    int a[] = {12, 35, 1, 10, 34, 1}, n = 6, f = INT_MIN, s = INT_MIN;
    for (int i = 0; i < n; i++) { if (a[i] > f) { s = f; f = a[i]; } else if (a[i] > s && a[i] != f) s = a[i]; }
    printf("Second largest = %d\n", s);
}
P(46) { int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, n = 9, e = 0, o = 0; for (int i = 0; i < n; i++) { if (a[i] % 2) o++; else e++; } printf("Even = %d, Odd = %d\n", e, o); }
P(47) {
    int a[] = {1, 2, 2, 3, 4, 4, 5}, n = 7, m = 0;
    for (int i = 0; i < n; i++) { int d = 0; for (int j = 0; j < m; j++) if (a[j] == a[i]) { d = 1; break; } if (!d) a[m++] = a[i]; }
    printarr(a, m);
}
P(48) {
    int a[] = {1, 3, 5, 7}, b[] = {2, 4, 6, 8, 10}, c[9], i = 0, j = 0, k = 0;
    while (i < 4 && j < 5) c[k++] = a[i] < b[j] ? a[i++] : b[j++];
    while (i < 4) c[k++] = a[i++];
    while (j < 5) c[k++] = b[j++];
    printarr(c, k);
}
P(49) { int a[] = {1, 2, 3, 4, 5, 6, 7}, n = 7, k = 3, b[7]; for (int i = 0; i < n; i++) b[i] = a[(i + k) % n]; printf("Left rotated by %d: ", k); printarr(b, n); }
P(50) {
    int a[] = {1, 2, 1, 3, 2, 1}, n = 6, seen[6] = {0};
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        int c = 0;
        for (int j = i; j < n; j++) if (a[j] == a[i]) { c++; seen[j] = 1; }
        printf("%d occurs %d time(s)\n", a[i], c);
    }
}
P(51) { int a[2][2] = {{1, 2}, {3, 4}}, b[2][2] = {{5, 6}, {7, 8}}; for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%d ", a[i][j] + b[i][j]); printf("\n"); } }
P(52) {
    int a[2][2] = {{1, 2}, {3, 4}}, b[2][2] = {{5, 6}, {7, 8}}, c[2][2];
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) { c[i][j] = 0; for (int k = 0; k < 2; k++) c[i][j] += a[i][k] * b[k][j]; }
    for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%d ", c[i][j]); printf("\n"); }
}
P(53) { int a[2][3] = {{1, 2, 3}, {4, 5, 6}}; for (int j = 0; j < 3; j++) { for (int i = 0; i < 2; i++) printf("%d ", a[i][j]); printf("\n"); } }
P(54) { int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, p = 0, s = 0; for (int i = 0; i < 3; i++) { p += a[i][i]; s += a[i][2 - i]; } printf("Main diagonal = %d, Secondary = %d\n", p, s); }
P(55) { int a[3][3] = {{1, 2, 3}, {2, 5, 6}, {3, 6, 9}}, sym = 1; for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (a[i][j] != a[j][i]) sym = 0; printf("Matrix is %ssymmetric\n", sym ? "" : "not "); }
P(56) { int a[] = {1, 3, 5, 7, 9}, n = 5, ok = 1; for (int i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) ok = 0; printf("Array is %ssorted\n", ok ? "" : "not "); }
P(57) { int a[] = {1, 2, 4, 5, 6}, n = 6, s = 0; for (int i = 0; i < 5; i++) s += a[i]; printf("Missing number = %d\n", n * (n + 1) / 2 - s); }
P(58) {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}, n = 9, cur = a[0], best = a[0];
    for (int i = 1; i < n; i++) { cur = (cur + a[i] > a[i]) ? cur + a[i] : a[i]; if (cur > best) best = cur; }
    printf("Max subarray sum = %d\n", best);
}
P(59) { int a[] = {2, 7, 11, 15}, n = 4, t = 9; for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (a[i] + a[j] == t) printf("Pair: %d + %d = %d\n", a[i], a[j], t); }
P(60) { int a[] = {16, 17, 4, 3, 5, 2}, n = 6, mx = -1; printf("Leaders: "); for (int i = n - 1; i >= 0; i--) if (a[i] > mx) { printf("%d ", a[i]); mx = a[i]; } printf("\n"); }

/* ===================== STRINGS (61-80) ===================== */
P(61) { char s[] = "programming"; int n = 0; while (s[n]) n++; printf("Length = %d\n", n); }
P(62) { char s[] = "hello"; int n = strlen(s); for (int i = 0; i < n / 2; i++) { char t = s[i]; s[i] = s[n - 1 - i]; s[n - 1 - i] = t; } printf("Reversed = %s\n", s); }
P(63) { char s[] = "madam"; int n = strlen(s), ok = 1; for (int i = 0; i < n / 2; i++) if (s[i] != s[n - 1 - i]) ok = 0; printf("\"%s\" is %sa palindrome\n", s, ok ? "" : "not "); }
P(64) { char s[] = "Programming Language"; int c = 0; for (int i = 0; s[i]; i++) if (strchr("aeiouAEIOU", s[i])) c++; printf("Vowels = %d\n", c); }
P(65) { char a[50] = "Hello, ", b[] = "World!"; strcat(a, b); printf("%s\n", a); }
P(66) { char a[] = "apple", b[] = "banana"; int r = strcmp(a, b); printf("%s\n", r == 0 ? "Equal" : r < 0 ? "First is smaller" : "First is greater"); }
P(67) { char a[] = "copy me", b[20]; int i = 0; for (; a[i]; i++) b[i] = a[i]; b[i] = 0; printf("Copied = %s\n", b); }
P(68) {
    char s[] = "Hello World", u[20], l[20]; int i;
    for (i = 0; s[i]; i++) { u[i] = toupper(s[i]); l[i] = tolower(s[i]); }
    u[i] = l[i] = 0;
    printf("Upper = %s\nLower = %s\n", u, l);
}
P(69) { char s[] = "the quick brown fox jumps"; int w = 0, in = 0; for (int i = 0; s[i]; i++) { if (s[i] == ' ') in = 0; else if (!in) { in = 1; w++; } } printf("Words = %d\n", w); }
P(70) { char s[] = "mississippi"; int f[256] = {0}; for (int i = 0; s[i]; i++) f[(unsigned char)s[i]]++; for (int c = 0; c < 256; c++) if (f[c]) printf("%c = %d\n", c, f[c]); }
P(71) { char s[] = "a b c d e", o[20]; int k = 0; for (int i = 0; s[i]; i++) if (s[i] != ' ') o[k++] = s[i]; o[k] = 0; printf("%s\n", o); }
P(72) {
    char a[] = "listen", b[] = "silent"; int f[26] = {0}, ok = strlen(a) == strlen(b);
    for (int i = 0; a[i]; i++) f[a[i] - 'a']++;
    for (int i = 0; b[i]; i++) f[b[i] - 'a']--;
    for (int i = 0; i < 26; i++) if (f[i]) ok = 0;
    printf("%s and %s are %sanagrams\n", a, b, ok ? "" : "not ");
}
P(73) { char s[] = "Hello World"; for (int i = 0; s[i]; i++) s[i] = isupper(s[i]) ? tolower(s[i]) : toupper(s[i]); printf("%s\n", s); }
P(74) {
    char s[] = "swiss"; int f[256] = {0};
    for (int i = 0; s[i]; i++) f[(unsigned char)s[i]]++;
    for (int i = 0; s[i]; i++) if (f[(unsigned char)s[i]] == 1) { printf("First non-repeating = %c\n", s[i]); return; }
    printf("None\n");
}
P(75) { char s[] = "find the longest word here", best[30] = "", *t = strtok(s, " "); while (t) { if (strlen(t) > strlen(best)) strcpy(best, t); t = strtok(NULL, " "); } printf("Longest word = %s\n", best); }
P(76) { char b[] = "101101"; int d = 0; for (int i = 0; b[i]; i++) d = d * 2 + (b[i] - '0'); printf("Decimal = %d\n", d); }
P(77) { int n = 45, i = 0; char b[33]; if (!n) b[i++] = '0'; while (n) { b[i++] = '0' + n % 2; n /= 2; } printf("Binary = "); while (i--) putchar(b[i]); printf("\n"); }
P(78) { int n = 255; printf("Octal = %o, Hex = %X\n", n, n); }
P(79) {
    char s[] = "Hello, World!"; int k = 3;
    for (int i = 0; s[i]; i++) { if (isupper(s[i])) s[i] = 'A' + (s[i] - 'A' + k) % 26; else if (islower(s[i])) s[i] = 'a' + (s[i] - 'a' + k) % 26; }
    printf("Encrypted = %s\n", s);
    for (int i = 0; s[i]; i++) { if (isupper(s[i])) s[i] = 'A' + (s[i] - 'A' + 26 - k) % 26; else if (islower(s[i])) s[i] = 'a' + (s[i] - 'a' + 26 - k) % 26; }
    printf("Decrypted = %s\n", s);
}
P(80) { char s[] = "the quick brown fox", *p = strstr(s, "brown"); if (p) printf("Found at position %ld\n", (long)(p - s)); else printf("Not found\n"); }

/* ===================== RECURSION (81-90) ===================== */
static long fact(int n) { return n <= 1 ? 1 : n * fact(n - 1); }
static int fib(int n) { return n < 2 ? n : fib(n - 1) + fib(n - 2); }
static int sod(int n) { return n ? n % 10 + sod(n / 10) : 0; }
static long pw(int b, int e) { return e ? b * pw(b, e - 1) : 1; }
static int gcdr(int a, int b) { return b ? gcdr(b, a % b) : a; }
static void hanoi(int n, char a, char b, char c) { if (!n) return; hanoi(n - 1, a, c, b); printf("Move disk %d from %c to %c\n", n, a, c); hanoi(n - 1, b, a, c); }
static void rev(char *s, int i, int j) { if (i >= j) return; char t = s[i]; s[i] = s[j]; s[j] = t; rev(s, i + 1, j - 1); }
static int pal(const char *s, int i, int j) { return i >= j ? 1 : (s[i] == s[j] && pal(s, i + 1, j - 1)); }
static void pr(int i, int n) { if (i > n) return; printf("%d ", i); pr(i + 1, n); }
static int asum(int *a, int n) { return n ? a[n - 1] + asum(a, n - 1) : 0; }

P(81) { printf("7! = %ld\n", fact(7)); }
P(82) { for (int i = 0; i < 10; i++) printf("%d ", fib(i)); printf("\n"); }
P(83) { printf("Sum of digits of 9875 = %d\n", sod(9875)); }
P(84) { printf("3^5 = %ld\n", pw(3, 5)); }
P(85) { printf("GCD(56, 98) = %d\n", gcdr(56, 98)); }
P(86) { hanoi(3, 'A', 'B', 'C'); }
P(87) { char s[] = "recursion"; rev(s, 0, strlen(s) - 1); printf("%s\n", s); }
P(88) { printf("\"level\" palindrome? %s\n", pal("level", 0, 4) ? "Yes" : "No"); }
P(89) { pr(1, 10); printf("\n"); }
P(90) { int a[] = {3, 6, 9, 12}; printf("Sum = %d\n", asum(a, 4)); }

/* ============ POINTERS, STRUCTS, FILES, BITS (91-100) ============ */
struct St { int id; char name[20]; float marks; };
static void swp(int *a, int *b) { int t = *a; *a = *b; *b = t; }
static int add(int a, int b) { return a + b; }
static int sub(int a, int b) { return a - b; }
static int mul(int a, int b) { return a * b; }

P(91) { int x = 10, y = 20; swp(&x, &y); printf("x=%d y=%d\n", x, y); }
P(92) { int a[] = {10, 20, 30, 40}, *p = a; for (int i = 0; i < 4; i++) printf("%d ", *(p + i)); printf("\n"); }
P(93) {
    int n = 5, s = 0, *a = malloc(n * sizeof(int));
    if (!a) { printf("Allocation failed\n"); return; }
    for (int i = 0; i < n; i++) { a[i] = (i + 1) * 10; s += a[i]; }
    printf("Sum = %d\n", s);
    free(a);
}
P(94) { struct St s = {1, "Rahim", 85.5f}; printf("ID=%d Name=%s Marks=%.1f\n", s.id, s.name, s.marks); }
P(95) {
    struct St a[3] = {{1, "Rahim", 78.5f}, {2, "Karim", 92.0f}, {3, "Sumaiya", 85.0f}};
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2 - i; j++) if (a[j].marks < a[j + 1].marks) { struct St t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }
    for (int i = 0; i < 3; i++) printf("%d. %s - %.1f\n", i + 1, a[i].name, a[i].marks);
}
P(96) {
    union U { int i; float f; char c; } u;
    u.i = 65; printf("As int: %d, as char: %c\n", u.i, u.c);
    u.f = 3.14f; printf("As float: %.2f (union size = %zu bytes)\n", u.f, sizeof u);
}
P(97) {
    FILE *f = fopen("demo.txt", "w"); char ln[50];
    if (!f) { printf("Cannot open file\n"); return; }
    fprintf(f, "Line 1\nLine 2\n"); fclose(f);
    f = fopen("demo.txt", "r");
    if (!f) { printf("Cannot read file\n"); return; }
    while (fgets(ln, sizeof ln, f)) printf("%s", ln);
    fclose(f);
}
P(98)  { unsigned n = 29, c = 0; while (n) { c += n & 1; n >>= 1; } printf("Set bits in 29 = %u\n", c); }
P(99)  { int n = 64; printf("%d is %sa power of 2\n", n, (n > 0 && (n & (n - 1)) == 0) ? "" : "not "); }
P(100) { int (*op[3])(int, int) = {add, sub, mul}; const char *nm[] = {"add", "sub", "mul"}; for (int i = 0; i < 3; i++) printf("%s(12, 5) = %d\n", nm[i], op[i](12, 5)); }

/* ===================== MAIN MENU ===================== */
#define T(n, t) {t, p##n}
static const struct { const char *title; void (*fn)(void); } probs[100] = {
    T(1,"Hello World"), T(2,"Sum of two numbers"), T(3,"Swap using temp variable"), T(4,"Swap without temp"),
    T(5,"Even or odd"), T(6,"Largest of three"), T(7,"Leap year"), T(8,"Simple interest"),
    T(9,"Area of circle"), T(10,"Celsius to Fahrenheit"), T(11,"Positive/negative/zero"), T(12,"Vowel or consonant"),
    T(13,"Grade from marks"), T(14,"Calculator (switch)"), T(15,"Sum of digits"), T(16,"Reverse a number"),
    T(17,"Palindrome number"), T(18,"Factorial"), T(19,"Fibonacci series"), T(20,"Prime check"),
    T(21,"Primes 1 to 50"), T(22,"Armstrong number"), T(23,"GCD"), T(24,"LCM"),
    T(25,"Power x^n"), T(26,"Count digits"), T(27,"Multiplication table"), T(28,"Sum of 1 to N"),
    T(29,"Perfect number"), T(30,"Strong number"), T(31,"Star triangle"), T(32,"Star pyramid"),
    T(33,"Number triangle"), T(34,"Floyd's triangle"), T(35,"Diamond"), T(36,"Pascal's triangle"),
    T(37,"Array sum and average"), T(38,"Max and min of array"), T(39,"Reverse an array"), T(40,"Linear search"),
    T(41,"Binary search"), T(42,"Bubble sort"), T(43,"Selection sort"), T(44,"Insertion sort"),
    T(45,"Second largest"), T(46,"Count even and odd"), T(47,"Remove duplicates"), T(48,"Merge sorted arrays"),
    T(49,"Rotate array left"), T(50,"Element frequency"), T(51,"Matrix addition"), T(52,"Matrix multiplication"),
    T(53,"Matrix transpose"), T(54,"Diagonal sums"), T(55,"Symmetric matrix"), T(56,"Check array sorted"),
    T(57,"Missing number"), T(58,"Max subarray (Kadane)"), T(59,"Pair with given sum"), T(60,"Leaders in array"),
    T(61,"String length"), T(62,"Reverse string"), T(63,"Palindrome string"), T(64,"Count vowels"),
    T(65,"Concatenate strings"), T(66,"Compare strings"), T(67,"Copy string"), T(68,"Upper/lower case"),
    T(69,"Word count"), T(70,"Character frequency"), T(71,"Remove spaces"), T(72,"Anagram check"),
    T(73,"Toggle case"), T(74,"First non-repeating char"), T(75,"Longest word"), T(76,"Binary to decimal"),
    T(77,"Decimal to binary"), T(78,"Decimal to octal/hex"), T(79,"Caesar cipher"), T(80,"Substring search"),
    T(81,"Factorial (recursion)"), T(82,"Fibonacci (recursion)"), T(83,"Digit sum (recursion)"), T(84,"Power (recursion)"),
    T(85,"GCD (recursion)"), T(86,"Tower of Hanoi"), T(87,"Reverse string (recursion)"), T(88,"Palindrome (recursion)"),
    T(89,"Print 1 to N (recursion)"), T(90,"Array sum (recursion)"), T(91,"Swap using pointers"), T(92,"Array via pointer"),
    T(93,"Dynamic memory (malloc)"), T(94,"Structure"), T(95,"Sort array of structures"), T(96,"Union"),
    T(97,"File write and read"), T(98,"Count set bits"), T(99,"Power of 2 check"), T(100,"Function pointers")
};

static void run(int n) { printf("--- Problem %d: %s ---\n", n, probs[n - 1].title); probs[n - 1].fn(); printf("\n"); }

int main(int argc, char *argv[]) {
    if (argc < 2) {
        for (int i = 0; i < 100; i++) printf("%3d. %s\n", i + 1, probs[i].title);
        printf("\nUsage: %s <1-100 | all>\n", argv[0]);
    } else if (strcmp(argv[1], "all") == 0) {
        for (int i = 1; i <= 100; i++) run(i);
    } else {
        int n = atoi(argv[1]);
        if (n >= 1 && n <= 100) run(n); else printf("Enter a number between 1 and 100.\n");
    }
    return 0;
}
