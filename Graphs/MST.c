foreach v element G.v do 
    v.key = infinite;
    v.pred = null;

s.key = 0 // start
initMinPriorityQ(PQ, G.v)
while(PQ != Null){
    v = extractMin(PQ);
    foreach u element v.adj do
        if u element PQ && w(v,u) < u.key then
            u.key = w(v,u) // assign new weight
            u.pred = v
            DecreaseKey(PQ, u, w(u,v))
}