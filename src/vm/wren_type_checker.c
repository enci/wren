// [WREN_TYPE_ANNOTATIONS] Compile-time type checker implementation.

#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#include "wren_type_checker.h"

void wrenTypeCheckerInit(TypeChecker* typeChecker)
{
  for (int i = 0; i < MAX_LOCALS; i++)
  {
    typeChecker->localTypes[i] = NULL;
    typeChecker->localTypeLengths[i] = 0;
  }

  typeChecker->returnType = NULL;
  typeChecker->returnTypeLength = 0;

  typeChecker->lastExprType = NULL;
  typeChecker->lastExprTypeLength = 0;
}

void wrenTypeCheckerSetLocalType(TypeChecker* typeChecker, int localIndex,
                                 const char* typeName, int typeLength)
{
  if (localIndex >= 0 && localIndex < MAX_LOCALS)
  {
    typeChecker->localTypes[localIndex] = typeName;
    typeChecker->localTypeLengths[localIndex] = typeLength;
  }
}

const char* wrenTypeCheckerGetLocalType(TypeChecker* typeChecker,
                                        int localIndex, int* length)
{
  if (localIndex >= 0 && localIndex < MAX_LOCALS)
  {
    *length = typeChecker->localTypeLengths[localIndex];
    return typeChecker->localTypes[localIndex];
  }

  *length = 0;
  return NULL;
}

void wrenTypeCheckerSetReturnType(TypeChecker* typeChecker,
                                  const char* typeName, int typeLength)
{
  typeChecker->returnType = typeName;
  typeChecker->returnTypeLength = typeLength;
}

void wrenTypeCheckerSetExprType(TypeChecker* typeChecker,
                                const char* typeName, int typeLength)
{
  typeChecker->lastExprType = typeName;
  typeChecker->lastExprTypeLength = typeLength;
}

void wrenTypeCheckerClearExprType(TypeChecker* typeChecker)
{
  typeChecker->lastExprType = NULL;
  typeChecker->lastExprTypeLength = 0;
}

bool wrenTypeCheckerTypesMatch(const char* typeA, int lengthA,
                               const char* typeB, int lengthB)
{
  // If either type is unknown (NULL), we can't check — treat as matching.
  if (typeA == NULL || typeB == NULL) return true;

  // Types match if they have the same length and content.
  if (lengthA != lengthB) return false;
  return memcmp(typeA, typeB, lengthA) == 0;
}

void wrenModuleTypeInfoInit(ModuleTypeInfo* info)
{
  info->count = 0;
}

void wrenModuleTypeInfoSet(ModuleTypeInfo* info, int symbolIndex,
                           const char* typeName, int typeLength)
{
  if (info->count >= MAX_MODULE_TYPE_ENTRIES) return;

  info->symbolIndices[info->count] = symbolIndex;
  info->typeNames[info->count] = typeName;
  info->typeLengths[info->count] = typeLength;
  info->count++;
}

const char* wrenModuleTypeInfoGet(ModuleTypeInfo* info, int symbolIndex,
                                  int* length)
{
  for (int i = 0; i < info->count; i++)
  {
    if (info->symbolIndices[i] == symbolIndex)
    {
      *length = info->typeLengths[i];
      return info->typeNames[i];
    }
  }

  *length = 0;
  return NULL;
}
