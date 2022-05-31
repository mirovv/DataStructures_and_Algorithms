// Directed graph without cycles
// is DAG iff has no back edges
// DFS is useful to check if Graph is DAG

int checkDAG(vertex){
    int cIsDAG = True;
    vertex.color = grey // visited
    for each u elementof v.adj do
        if u.color = white then return cIsDAG && checkDAG(u);
        else if u.color = grey then return False;
    vertex.color = black // checked
    return cIsDAG;
}

run checkDAG on every vertex

first: make v.color white

for v in G.v do 
    v.color = "white";

second: run checkDAG on every vertex of G

GisDAG = True;
for v in G.v;
    if v.col == "white"
        GisDAG = GisDAG && checkDAG(v);