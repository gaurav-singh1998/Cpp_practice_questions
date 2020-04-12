// non zero backward edge && a non-full forward edge
// max-flow on an augmented path is the value of min weight
// for every vertex except of src and dest (inflow) == (outflow)
// if the residual flow for every edge > 0 than in the path, then the path is augmented path
// residual flow = capacity - flow

//ford fulkerson algorithm
// setup the directed residual graph with the edge capacity == original graph weight
// maxflow=0;
// while(there exist any augmented path from source --> sink){
// find 'f', the minimum edge weight along the current path
// Decrease the capacity of all the forward edges by 'f'
// Increase the capacity of all the backward edges by 'f'
// maxflow += f 
//}