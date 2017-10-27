using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AzarashiController : MonoBehaviour
{
   private Rigidbody2D rb2d;
   private Animator animator;
   private float angle;
   private bool isDead;

   public float maxHeight;
   public float flapVelocity;
   public float relativeVelocityX;
   public GameObject sprite;

   public bool IsDead()
   {
      return isDead;
   }
   
   void Awake()
   {
      rb2d = GetComponent<Rigidbody2D>();
      animator = sprite.GetComponent<Animator>();
   }

   void Update()
   {
      if (Input.GetButtonDown("Fire1") && transform.position.y < maxHeight)
      {
         Flap();
      }

      ApplyAngle();
      
      animator.SetBool("flap", angle >= 0.0f);
   }

   public void Flap()
   {
      if(isDead) return;
      
      rb2d.velocity = new Vector2(0.0f, flapVelocity);
   }

   void ApplyAngle()
   {
      float targetAngle;
      
      if (isDead)
      {
         targetAngle = -90.0f;
      }
      else
      {
         targetAngle = Mathf.Atan2(rb2d.velocity.y, relativeVelocityX) * Mathf.Rad2Deg;         
      }

      // angleをtargetAngleにいきなり書き換えると急激に角度が変わった感が出てしまう可能性があるので、
      // 現在のangleとtargetAngleの中間値をとる。
      // ここでは、差が毎フレーム(1 - Time.deltaTime * 10.0f)倍になるように設定されている。
      angle = Mathf.Lerp(angle, targetAngle, Time.deltaTime * 10.0f);

      sprite.transform.localRotation = Quaternion.Euler(0.0f, 0.0f, angle);
   }

   private void OnCollisionEnter2D(Collision2D other)
   {
      if(isDead) return;

      isDead = true;
   }
}
