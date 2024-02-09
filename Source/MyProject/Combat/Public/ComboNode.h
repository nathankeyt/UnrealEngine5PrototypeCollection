// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ComboNode.generated.h"

class UAttackWrapperNode;
/**
 * 
 */
UCLASS(Blueprintable, EditInlineNew)
class MYPROJECT_API UComboNode : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttackNodes)
	UAttackWrapperNode* MainAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttackNodes)
	UAttackWrapperNode* AltAttack;
};
