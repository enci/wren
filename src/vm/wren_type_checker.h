// [WREN_TYPE_ANNOTATIONS] Compile-time type checker for optional type annotations.
// Tracks type annotations and inferred expression types during single-pass
// compilation, emitting warnings (not errors) when mismatches are detected.

#ifndef wren_type_checker_h
#define wren_type_checker_h

// MAX_LOCALS is defined in wren_compiler.c (256). We mirror it here to size
// the parallel type annotation arrays. If it changes upstream, update this.
#ifndef MAX_LOCALS
#define MAX_LOCALS 256
#endif

typedef struct
{
  // Type annotations for local variables, indexed parallel to compiler->locals[].
  // NULL means no annotation is present for that local.
  // Pointers point directly into the source code string.
  const char* localTypes[MAX_LOCALS];
  int localTypeLengths[MAX_LOCALS];

  // Return type annotation for the current function/method.
  // NULL if no return type annotation was specified.
  const char* returnType;
  int returnTypeLength;

  // The inferred type of the last expression that was compiled.
  // Set by literal parsing functions, cleared to NULL for complex/unknown
  // expressions. NULL means "type unknown, skip checking".
  const char* lastExprType;
  int lastExprTypeLength;
} TypeChecker;

// Initializes all fields of [typeChecker] to their default (empty) state.
void wrenTypeCheckerInit(TypeChecker* typeChecker);

// Stores a type annotation for the local variable at [localIndex].
void wrenTypeCheckerSetLocalType(TypeChecker* typeChecker, int localIndex,
                                 const char* typeName, int typeLength);

// Returns the type annotation for the local at [localIndex], or NULL if none.
const char* wrenTypeCheckerGetLocalType(TypeChecker* typeChecker,
                                        int localIndex, int* length);

// Sets the return type annotation for the current function/method.
void wrenTypeCheckerSetReturnType(TypeChecker* typeChecker,
                                  const char* typeName, int typeLength);

// Sets the inferred type of the last compiled expression.
void wrenTypeCheckerSetExprType(TypeChecker* typeChecker,
                                const char* typeName, int typeLength);

// Clears the inferred expression type (sets to NULL/unknown).
void wrenTypeCheckerClearExprType(TypeChecker* typeChecker);

// Compares two type names. Returns true if they match (same string content).
// Returns true if either is NULL (unknown types are not checked).
bool wrenTypeCheckerTypesMatch(const char* typeA, int lengthA,
                               const char* typeB, int lengthB);

#endif
