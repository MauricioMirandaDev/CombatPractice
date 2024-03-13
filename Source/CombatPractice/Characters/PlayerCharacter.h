
#pragma once

#include "CoreMinimal.h"
#include "CombatCharacter.h"
#include "PlayerCharacter.generated.h" 

class AEnemyCharacter;
class AGrapplePoint; 
class UAnimMontage; 

UCLASS()
class COMBATPRACTICE_API APlayerCharacter : public ACombatCharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Functions used for combat
	virtual void UpdateMovement(bool bPauseMovement) override;

	virtual void ResetAttack() override;

	// Functions used for health system 
	virtual void TakeDamage(FAttackAnimation AttackAnimation, FVector AttackLocation) override;

	virtual void AfterDeath() override; 

	// Function used for lock on system
	void EnemyDefeated(AActor* Enemy); 

	// Function used for rope
	void SetRopeAttached(bool bAttach); 

	// Friend class that handles input bindings
	friend class ACombatPlayerController; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Functions used for movement
	virtual void Jump() override; 

	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode) override; 

	// Function used for health system 
	virtual void OnDeath() override; 

private:
	// Components for camera control
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	// Components, functions, and variables for combat
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	FAttackAnimation LightAttack; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TArray<UAnimMontage*> LightAttackVariations; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	FAttackAnimation JumpAttack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	FAttackAnimation HeavyAttack;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bJumpPressed; 

	void LightAttackPressed(); 

	void HeavyAttackPressed(); 

	float DefaultWalkSpeed; 

	// Components, functions, and variables for lock-on system
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lock-On System", meta = (AllowPrivateAccess = "true"))
	float LockOnCameraOffset; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lock-On System", meta = (AllowPrivateAccess = "true"))
	float MaxLockOnDistance; 

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bIsLockedOn;

	void LockOn();

	AEnemyCharacter* FindClosestEnemy();

	void LockOnBehavior();

	void BeginLockingOn(); 

	void StopLockingOn(); 

	void LockedOnMovement();

	AEnemyCharacter* FindNearbyEnemy(FVector Direction);

	void SwitchLockedOnEnemy(FVector Direction); 

	AEnemyCharacter* LockedOnEnemy;

	bool bEnemyJustDefeated; 

	// Components for rope
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rope", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* RopeHolster;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rope", meta = (AllowPrivateAccess = "true"))
	class UCableComponent* Rope;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* CastRopeAnim; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* DetachRopeAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rope", meta = (AllowPrivateAccess = "true"))
	float RopeLength; 

	void SearchForGrapplePoints(); 

	void CastRope(); 

	AGrapplePoint* ClosestGrapplePoint; 

	bool bCanGrapple; 

	bool bIsGrappling; 
};
