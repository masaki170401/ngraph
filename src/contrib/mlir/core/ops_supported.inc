// List of all ops supported by MLIR backend end-to-end
#ifndef MLIR_OP
#define MLIR_OP
#endif

MLIR_OP(Add)
MLIR_OP(ArgMin)
MLIR_OP(ArgMax)
MLIR_OP(Divide)
MLIR_OP(Dot)
MLIR_OP(Concat)
MLIR_OP(Convolution)
MLIR_OP(Gather)
MLIR_OP(Greater)
MLIR_OP(Less)
MLIR_OP(GreaterEq)
MLIR_OP(LessEq)
MLIR_OP(Equal)
MLIR_OP(NotEqual)
MLIR_OP(Maximum)
MLIR_OP(Minimum)
MLIR_OP(Multiply)
MLIR_OP(Negative)
MLIR_OP(Subtract)
MLIR_OP(Relu)
// Add new supported ops here

#undef MLIR_OP
