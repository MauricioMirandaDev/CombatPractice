
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UAnimMontage; 
class ABaseWeapon; 

UCLASS()
class COMBATPRACTICE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	friend class UCAN_SetAttackEffects; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Functions and components for camera control
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera; 

	// Functions for movement
	void MoveForward(float Scale);

	void MoveRight(float Scale);

	// Functions, components, and variables for combat
	void LightAttack();

	void AttackEffects(bool bIsStart);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ABaseWeapon> WeaponClass; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* LightAttackAnimation; 

	ABaseWeapon* Weapon; 

	bool bCanAttack; 
};
