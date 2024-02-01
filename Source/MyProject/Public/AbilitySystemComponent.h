// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "Components/ActorComponent.h"
#include "AbilitySystemComponent.generated.h"

class UEquipAbilityBase;
class ABaseCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UAbilitySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilitySystemComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, meta = (AllowPrivateAccess = "true"))
	TArray<UAbility*> Abilities;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<bool> ActiveAbilities;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UEquipAbilityBase* MainEquippedAbility;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Server, Reliable)
	void ActivateAbility(int AbilityIndex, ABaseCharacter* Character);

	UFUNCTION(Server, Reliable)
	void EndAbilityActivation(int AbilityIndex);
 
	UFUNCTION(BlueprintCallable)
	TArray<UAbility*> GetAbilities() const { return Abilities; }
	
	UFUNCTION(BlueprintCallable)
	UEquipAbilityBase* GetMainEquippedAbility();
};
