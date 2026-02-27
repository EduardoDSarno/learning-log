- Changed SHA module to simplify external calls by adding sha256_hash_bytes, that does padding,schedule,compression into out_H
- sha256_hash_hex calls sha256_hash_bytes then format into hex
- Now external files can hash arbitrary buffers like:
char hex[SHA_OUT_HEX_RESULT_LENGTH];

char hex[SHA_OUT_HEX_RESULT_LENGTH];sha256_hash_hex(data_ptr, data_len, hex);