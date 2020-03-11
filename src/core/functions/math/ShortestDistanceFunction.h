#ifndef ShortestDistanceFunction_h
#define ShortestDistanceFunction_h

#include <stdio.h>
#include <set>
#include <vector>
#include "RbVector.h"
#include "TypedFunction.h"
#include "RbVectorImpl.h"

namespace RevBayesCore {
class DagNode;
template <class valueType> class TypedDagNode;
    
    
    /**
     * \brief Shortest Distance Along A Graph.
     *
     * Computes the shortest distance from each node in the graph to every other node in the graph
     * The function computes a vector of vectors where the x[i][j] position returns the shortest distance between nodes i and j.
     *
     *@param adj a matrix denoting the connectivity of nodes. adj[i][j]>0 denotes connectivity
     *@param dist a matrix denoting the distance between connected nodes.
     *
     */
    class ShortestDistanceFunction : public TypedFunction<RbVector<RbVector<double> > > {
        
    public:
        ShortestDistanceFunction(const TypedDagNode<RbVector<RbVector<long> > >* adj, const TypedDagNode<RbVector<RbVector<double> > >* dist);
        
        ShortestDistanceFunction*                               clone(void) const;                                                  //!< Create a clone.
        void                                                    update(void);                                                       //!< Recompute the value
        
    protected:
        void                                                    swapParameterInternal(const DagNode *oldP, const DagNode *newP);    //!< Implementation of swaping parameters
        
    private:
        std::vector<std::set<size_t> >                          createAdjacencySets(const RbVector<RbVector<long> >& adj);
        RbVector<RbVector<double> >                             findShortestPaths(const RbVector<RbVector<long> >& adj, const RbVector<RbVector<double> >& dist);
        
        size_t                                                  num_nodes;
        
        const TypedDagNode<RbVector<RbVector<long> > >*          adjacencies;
        const TypedDagNode<RbVector<RbVector<double> > >*       distances;
    };
}



#endif /* ShortestDistanceFunction_h */
