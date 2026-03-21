CC = gcc
CFLAGS = -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lsecp256k1

cblockchain: block/block.c blockchain/blockchain.c hash/hash.c nodes/node.c serialize/serialize.c SHA_256/sha256.c transaction/transaction.c
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o cblockchain