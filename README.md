# README

Clangを学校のPC以外からでも開発できるようにするためのリポジトリです。

## Usage

### コンテナを立ち上げる

```sh
docker compose up -d
```

### コンテナに接続する

```sh
docker container exec -it clang-dev-container /bin/sh
```
`ctrl + d`でデタッチできます。

### コンテナを停止する

```sh
docker compose stop
```
