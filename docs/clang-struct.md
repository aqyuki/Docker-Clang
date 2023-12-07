# C 言語の構造体に付いて

## 構造体とは

色々な種類の関連するデータをまとめて、１つのかたまりにしたもの。

例）\
本というデータをプログラム中で扱うときに、「本のタイトル」・「ジャンル」・「値段」などの情報をバラバラで管理するよりも１つのまとまりで管理したほうが楽

## 定義方法

```c
// 構造体の定義
struct _book {
  char[100] title; // title has a book title
  int       price; // price has a price number
};

// _book型の変数の定義
struct _book b;

/*
 * 下の書き方だとエラーになる
 * _book b;
*/s
```

構造体の定義・構造体変数の定義方法は以上の通り。ただし、この書き方だけだと変数を宣言するときにいちいち`struct _book b`というふうに書かなければならないので以下のように`typedef`を使うと良い。

```c
struct _book  {
  char[100] title;
  int       price;
};
typedef struct _book book_t; // この行を追加

book_t b; // OK
```

## 構造体の参照方法

### メンバ参照（直接）

```c

#include <stdio.h>

struct _book  {
  char[100] title;
  int       price;
};
typedef struct _book book_t;

int main(){
  // 変数の定義と初期化
  book_t b1 = { "book1", 100 }, b2;

  char title[100];
  title = b1.title; // titleに"book1"が代入される。

  b2 = b1; //　b2にb1の構造体がコピーされる

  printf("b1 title : %s\n",b1.title);
  printf("title    : %s\n",title);
  printf("b2 title : %s\n",b2.title);
}
```

### メンバ参照（ポインタを使用）

```c
#include <stdio.h>

struct _book {
  char[100] title;
  int       price;
}
typedef struct _book book_t;

int main() {
  book_t  b  = { "book1", 100 };
  book_t* bp = &b;
  char[100] title;

  title = bp -> title; // bpはポインタ型の変数なのでアロー演算子を使用して値を取り出す
  printf("title : %s\n", title);
}
```
