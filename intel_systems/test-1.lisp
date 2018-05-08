(defun $sorted? (lst)
  "($sorted? '(1 2 3 2)) = Nil"
  (if (< (length lst) 2) t
    (and (< (first lst) (second lst))
         ($sorted? (cdr lst)))))

(defun $merge-sort (lst)
  "($merge-sort '(3 2 1)) = (1 2 3)"
  (if ($sorted? lst) lst
      (multiple-value-bind (q _) (floor (length lst) 2)
        (merge 'list
               ($merge-sort (subseq lst 0 q))
               ($merge-sort (subseq lst q))
               #'<))))

(defun $deconstruct (st)
  "($deconstruct (list 1 (list 2 (list 3 '(4))))) = (1 2 3 4)"
  (if st (cons (car st) ($deconstruct (cadr st)))))


(defun $construct (lst)
  "($construct '(1 2 3 4)) = ((((1) 2) 3) 4)"
  (reduce #'(lambda (acc e) (list acc e))
          (cdr lst)
          :initial-value (list (car lst))))

(defun $stairs (lst)
  "($stairs (list 1 (list 2 (list 3 '(4))))) = ((((1) 2) 3) 4)"
  ($construct ($deconstruct lst)))
