
(defn read-int []
  (Integer/parseInt (read-line)))

(defn get-mask [from]
  (loop [ax from mask 0]
    (if (= ax 0)
          mask
          (recur (quot ax 10) (bit-or mask (bit-shift-left 1 (rem ax 10)))))))

(defn add-bits [from to]
  (bit-or (get-mask from) to))

(defn play [N]
  (loop [cur 0 seen 0]
    (if (= seen 1023)
          cur
        (let [flw (+ cur N)]
          (recur flw (add-bits flw seen))))))

(defn solve [N]
 (if (= 0 N) "INSOMNIA" (play N)))

(def T (read-int))

(doseq [tc (range T)]
  (println (str "Case #" (+ 1 tc) ": " (solve (read-int)))))
