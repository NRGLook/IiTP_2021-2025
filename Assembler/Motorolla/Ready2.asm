 org $8000
 ldx #01
 ldd 0,x
 addd 3,x
 std 0,x
 dex
 ldaa 0,x
 adca 3,x
 staa 0,x
 ldx #$2
 ldaa 0,x
 ldab 3,x
 sba
 dex
 ldaa 0,x
 sbca 3,x
 staa 0,x
 dex
 ldaa 0,x
 sbca 3,x
 staa 0,x