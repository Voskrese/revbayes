#ifndef Func_jc_H
#define Func_jc_H

#include <string>
#include <iosfwd>
#include <vector>

#include "RlRateMatrix.h"
#include "RlTypedFunction.h"
#include "DeterministicNode.h"
#include "DynamicNode.h"
#include "RateGenerator.h"
#include "RevPtr.h"
#include "RlDeterministicNode.h"
#include "TypedDagNode.h"
#include "TypedFunction.h"

namespace RevLanguage {
class ArgumentRules;
class TypeSpec;
    
    /**
     * The RevLanguage wrapper of the JC rate matrix function.
     *
     * The RevLanguage wrapper of the JC rate matrix connects
     * the variables/parameters of the function and creates the internal JcRateMatrixFunction object.
     * Please read the JcRateMatrixFunction.h for more info.
     *
     *
     * @copyright Copyright 2009-
     * @author The RevBayes Development Core Team (Sebastian Hoehna)
     * @since 2014-08-14, version 1.0
     *
     */
    class Func_jc : public TypedFunction<RateMatrix> {
        
    public:
        Func_jc( void );
        
        // Basic utility functions
        Func_jc*                                                        clone(void) const;                                          //!< Clone the object
        static const std::string&                                       getClassType(void);                                         //!< Get Rev type
        static const TypeSpec&                                          getClassTypeSpec(void);                                     //!< Get class type spec
        std::string                                                     getFunctionName(void) const;                                //!< Get the primary name of the function in Rev
        const TypeSpec&                                                 getTypeSpec(void) const;                                    //!< Get the type spec of the instance
        
        // Function functions you have to override
        RevBayesCore::TypedFunction<RevBayesCore::RateGenerator>*       createFunction(void) const;                                 //!< Create internal function object
        const ArgumentRules&                                            getArgumentRules(void) const;                               //!< Get argument rules
        
    };
    
}

#endif
