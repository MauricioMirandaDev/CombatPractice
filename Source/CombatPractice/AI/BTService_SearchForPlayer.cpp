
#include "BTService_SearchForPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CombatPractice/AI/EnemyAIController.h"
#include "CombatPractice/Characters/EnemyCharacter.h"
#include "CombatPractice/Characters/PlayerCharacter.h"

// Set default values
UBTService_SearchForPlayer::UBTService_SearchForPlayer()
{
	NodeName = TEXT("Search for Player");
}

// Determine if the owning enemy can see the player or not
void UBTService_SearchForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (OwningEnemy->PlayerReference && OwningEnemy->CanSeePlayer())
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), OwningEnemy->PlayerReference->GetActorLocation());
	else
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
}
