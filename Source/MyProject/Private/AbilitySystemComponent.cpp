// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemComponent.h"
#include "BaseCharacter.h"

// Sets default values for this component's properties
UAbilitySystemComponent::UAbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	SetIsReplicatedByDefault(true);

	Abilities.Init(nullptr, 10);
}


// Called when the game starts
void UAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAbilitySystemComponent::ActivateAbility_Implementation(int AbilityIndex, ABaseCharacter* Character)
{
	if (AbilityIndex >= 0 && AbilityIndex < Abilities.Num()  && Abilities[AbilityIndex] != nullptr)
	{
		Abilities[AbilityIndex]->Activate(Character);
	}
}

void UAbilitySystemComponent::EndAbilityActivation_Implementation(int AbilityIndex)
{
	if (AbilityIndex >= 0 && AbilityIndex < Abilities.Num() && Abilities[AbilityIndex] != nullptr)
	{
		Abilities[AbilityIndex]->EndActivation();
	}
}



