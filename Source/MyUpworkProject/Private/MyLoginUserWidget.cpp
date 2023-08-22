// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLoginUserWidget.h"
#include "MyHUD.h"

//makes RegistrationMenu appear
void UMyLoginUserWidget::OpenRegistrationMenu() {
	UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AMyHUD>()->OpenRegistrationWidget();
}

//makes OpenTraineeMenu appear
void UMyLoginUserWidget::OpenHomeTraineeMenu() {
	UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AMyHUD>()->OpenHomeTraineeWidget();

}
