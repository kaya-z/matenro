        bits 16
        cpu     8086
        org     0x100
        db      "Hello from the small model",13,10,"$"      ; 0x100, 0x1c bytes
        times   0x24-($-$$) db 0
        db      "version ok, RETF ends",13,10,"$"
        times   0x3f-($-$$) db 0
        db      "wrong version",13,10,"$"
