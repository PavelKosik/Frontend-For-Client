// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHomeTraineeUserWidget.h"
#include "MyHUD.h"

//makes LoginMenu appear
void UMyHomeTraineeUserWidget::OpenLoginMenu() {
	UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AMyHUD>()->OpenLoginWidget();
}
