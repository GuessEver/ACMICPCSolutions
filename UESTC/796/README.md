dp\[i\]\[j\]表示已经挂掉了i个怪物，还有j的血量的概率  
那么已挂掉的就有i个，未挂的有n-i个  
地推方程式就很简单了 dp\[i+1\]\[k\] = sigma\(对于所有未挂掉的k，满足 \(ak & j\) = k \) \{ dp\[i\]\[j\] / (n - i) \};  
最后的答案就是sigma\(1, n\)\{dp\[i\]\[0\] * i\}  

那么现在的难题就是如何找到未挂掉的k  

再看，对于任意一个怪物k，如果已经挂掉，我们有，\(ak & j\) = j（用二进制证明）  
而如果没有挂掉则有 \(ak & j\) = j || \(ak & j\) != j  
即如果有cnt个怪物满足 \(ak & j\) = j，那么一定有i个已经挂掉，cnt-i个没有挂掉  
所以dp\[i+1\]\[j\] += sigma\(1, cnt-i\) \{ dp\[i\]\[j\] / \(n-i\) \};  
上式其实就是 dp\[i+1\]\[j\] += \(cnt-i\) * dp\[i\]\[j\] / \(n-i\);  
剩下的就简单啦，dp\[i+1\]\[ak&j\] += sigma\(对于所有k满足ak&j != j\) \{ dp\[i\]\[j\] / \(n-i\) \};  
