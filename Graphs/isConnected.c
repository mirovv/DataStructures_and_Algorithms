int isConnected(G){
    initQueue(Q);
    Enqueue(Q,s);
    while(Q != Null) do
        v = Dequeue(Q);
        v.color = Grey
        foreach u element of v.adj do
            if u.color = white then
                Enqueue(Q,u);
    
    foreach v element of G.v do
        if v.color == white then
            return 0;
    return 1;
}