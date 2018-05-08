(defun $gcd (a b)
  "($gcd 6 9) = 3"
  (if (= b 0) a
    (gcd b (mod a b))))

(defun $sum (lst)
  "($sum '(1 2 -1)) = 2"
  (apply #'+ lst))

(defun $sorted? (lst)
  "($sorted? '(1 2 3 2)) = Nil"
  (if (< (length lst) 2) t
    (and (< (first lst) (second lst))
        ($sorted? (cdr lst)))))

(defun $lcm (a b)
  "($lcm 6 9) = 18"
  (/ (* a b) (gcd a b)))

(defun $interleaved? (lst)
  "($interleaved? '(1 -2 3 -4 5)) = T"
  (if lst
      (if (> (length lst) 1)
          (and (> (first lst) 0) (< (second lst) 0) ($interleaved? (cddr lst)))
          (> (car lst) 0))
      t))

(defun $reverse (lst)
  "($reverse '(1 2 3 4)) = (4 3 2 1)"
  (reduce #'(lambda (acc e) (cons e acc))
          lst
          :initial-value nil))

(defun $gorner (p x)
  "($gorner '(1 2 3) 2) => x^2 + 2*x + 3) = 27"
  (reduce #'(lambda (acc c) (+ c (* x acc)))
          p
          :initial-value 0))

(defun $min (lst)
  "($min (list '(1 2) '(4 3))) = 1"
  (apply #'min
         (mapcar #'(lambda (l) (apply #'min l))
                 lst)))

;;; WTF???

(defun $sum-mat (m)
  "($sum-mat (list '(1 2 3) '(3 2 1) '(4 4 4))) = 24"
  (apply #'+
         (mapcar #'(lambda (l) (apply #'+ l))
                 m)))

(defun $tree-subs (tree old new)
  "($tree-subs (list (list '(1 3) '(2 1)) (list '(3 2) '(2))) 2 0)"
  (if (numberp tree)
      (if (= tree old) new tree)
      (mapcar #'(lambda (e) ($tree-subs e old new))
              tree)))

;;; WTF???

(defun $odd-negate (lst)
  "($odd-negate '(1 2 3 4 5 6 7)) = (1 -2 3 -4 5 -6 7)"
  (if (> (length lst) 1)
      (cons (first lst)
            (cons (* -1 (second lst))
                  ($odd-negate (cddr lst))))
      lst))

(defun $remove-elem (lst e)
  "($remove-elem '(1 4 3 4) 4) = (1 3)"
  (remove-if #'(lambda (x) (= x e)) lst))

(defun $min-max (tree &key (start-with-min t))
  "($min-max (list (list '(1) '(2)) (list '(3) '(4)))) = 2"
  (if (numberp tree)
      tree
      (let ((res (mapcar #'(lambda (tree) ($min-max tree :start-with-min (not start-with-min))) tree)))
        (if start-with-min
            (apply #'min res)
            (apply #'max res)))))

(defun $insert (lst e i)
  "($insert '(1 2 4) 3 2) = (1 2 3 4)"
  (if (= 0 i)
      (cons e lst)
      (cons (car lst) ($insert (cdr lst) e (- i 1)))))

(defun $stairs (lst)
  "($stairs '(1 2 3 4)) = ((((1) 2) 3) 4)"
  (reduce #'(lambda (acc e) (list acc e))
          (cdr lst)
          :initial-value (list (car lst))))

(defun $merge-sort (lst)
  "($merge-sort '(3 2 1)) = (1 2 3)"
  (if (sorted? lst)
      (multiple-value-bind (q _) (floor (length lst) 2)
        (merge 'list
          ($merge-sort (subseq lst 0 q))
          ($merge-sort (subseq lst q))
          #'<))
      lst))

(defun $transpose (m)
  "($transpose (list '(1 2 3) '(3 2 1))) = ((1 3) (2 2) (3 1))"
  (if (car m)
      (cons (mapcar #'car m) ($transpose (mapcar #'cdr m)))
      nil))

(defun $remove-even (lst)
  "($remove-even '(1 2 3 4 5 6 7)) = (1 3 5 7)"
  (if (> (length lst) 1)
      (cons (car lst) ($remove-even (cddr lst)))
      lst))

(defun $snake-merge (a b)
  "($snake-merge '(1 2 3) '(4 5 6)) = (1 4 2 5 3 6)"
  (if a
      (cons (car a)
            (cons (car b)
                  ($snake-merge (cdr a) (cdr b))))
    nil))
