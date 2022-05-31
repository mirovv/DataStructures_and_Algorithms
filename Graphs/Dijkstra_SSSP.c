Relax(u,v,w){
    if v.dist > u.dist + w(u,v)
        v.dist = u.dist + w(u,v)
        v.pred = u
}


foreaach v element G do
    v.dist = infinity;

s.dist = 0 // start
InitMinPQ(PQ, G)
while(PQ != Null){
    v = extractMin(PQ);
    foreach u element v.adj do
        Relax(u,v,w)
        decreaseKey(PQ, u, u.dist)
}