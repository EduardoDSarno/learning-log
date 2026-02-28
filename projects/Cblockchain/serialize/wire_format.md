-index → uint32 (4 bytes)
-timestamp → uint64 (8 bytes)
-previous_hash → 32 bytes (raw)
-nonce → uint32 (4 bytes)
-data_len → uint32 or uint64 (length prefix)
-data → data_len bytes
-tx_count → uint32
-transactions → each transaction serialized with its own length/fields

-Those above are also the order on which the serialization and deserialization will 
happen