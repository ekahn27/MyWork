;;init file


;;line numbers
(global-linum-mode t)

;;remove delay when highlighting brackets
(setq show-paren-delay 0)
;;bracket highlighting
(show-paren-mode 1)

;;Change tab key behavior to insert spaces instead
;;(setq-default indent-tabs-mode nil)

;;set the number of spaces that tab key inserts to 4
(setq c-default-style "linux"
      c-basic-offset 4)

;;smooth scrolling, one line at a time (no jumping)
(setq scroll-step 1
      scroll-conservatively 10000)
